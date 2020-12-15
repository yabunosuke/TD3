#include "Looper.h"
//�����ɌĂяo�������V�[����include
#include "TitleScene.h"
#include "SelectScene.h"
#include "GameScene.h"
using namespace std;

Looper::Looper() {
	//���\�[�X�ǂݍ���
	Parameter parameter;
	_sceneStack.push(make_shared<TitleScene>(this, parameter));	//�^�C�g����ʂ��X�^�b�N�ɓ����
	_sceneStack.top()->init();		//�V�[���̏�����
}

bool Looper::loop() {
	//keyboard���̏��A�b�v�f�[�g
	_sceneStack.top()->update();	//�X�^�b�N�̈�ԏ���X�V
	_sceneStack.top()->draw();		//�X�^�b�N�̈�ԏ��`��
	_fps.wait();

	return true;
}


void Looper::onSceneChanged(const Scenes scene, const Parameter &parameter, const bool stackClear) {
	if(!_sceneStack.empty()) {
		
	}
	if (stackClear == true) {				//�X�^�b�N���N���A����ݒ�Ȃ�
		while (!_sceneStack.empty()) {		//�X�^�b�N������ɂȂ�܂Ń|�b�v����
			_sceneStack.pop();
		}
	}
	switch (scene) {
	case Title:
		_sceneStack.push(make_shared<TitleScene>(this, parameter));
		break;

	case Select:
		_sceneStack.push(make_shared<SelectScene>(this, parameter));
		break;

	case Game:
		_sceneStack.push(make_shared<GameScene>(this, parameter));
		break;

	default:
		//���݂��Ȃ��V�[�����X�^�b�N�g�b�v�ɂ���ۂ̃G���[����
		break;
	}
	_sceneStack.top()->init();
}

void Looper::sceneStackPop() {
	_sceneStack.pop();
	_sceneStack.top()->init();
}
