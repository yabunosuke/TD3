#include "Fps.h"
#include "DxLib.h"
#include "CalcUtils.h"

//���ƂŐ�y�ɕ���

const static int LIST_LEN_MAX = 120;	//�ő�120�t���[���ŏ���
const static int FPS = 60;				//FPS
const static int UPINTVL = 60;			//�X�V�p

Fps::Fps() :_counter(0), _fps(0) {
}

void Fps::wait() {
	_counter++;
	Sleep(getWaitTime());
	regist();
	if (_counter == UPINTVL) {
		updateAverage();
		_counter = 0;
	}
}

void Fps::draw() const {
	if (_fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%03.1f fps", _fps);
}

void Fps::regist() {
	_list.push_back(GetNowCount());		//���݂̎������L��
	if (_list.size() > LIST_LEN_MAX) {	//�킩��R�ꂽ��|�b�v
		_list.pop_front();
	}
}

unsigned Fps::getWaitTime() const {
	int len = (int)_list.size();
	if (len == 0) {
		return 0;
	}
	int shouldTookTime = (int)(1000 / 60.f * (len));
	int actuallyTookTime = GetNowCount() - _list.front();
	int waitTime = shouldTookTime - actuallyTookTime;
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned)(waitTime);
}

void Fps::updateAverage() {
	int len = (int)_list.size();
	if (len < LIST_LEN_MAX) {
		return;
	}
	int tookTime = _list.back() - _list.front();
	float average = (float)tookTime / (len - 1);
	if (average == 0) {
		return;
	}
	_fps = CalcUtils::RoundPoint(1000 / average, 2);
}