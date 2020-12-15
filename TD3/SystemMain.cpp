#include "DxLib.h"
#include "SystemMain.h"
#include "Looper.h"
#include"WindowSize.h"

//DX���C�u�����̏�����
bool SystemMain::init() const {
	//SetWindowIconID(101);							//�E�B���h�E�A�C�R��
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h�ɐݒ�
	SetMainWindowText("TITLE");				//�E�B���h�E�^�C�g��
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);	//�T�C�Y�ύX�s��
	SetWindowSizeExtendRate(1.0);					//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetGraphMode(GetWinSize().x, GetWinSize().y, 32);		//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
	SetAlwaysRunFlag(TRUE);							//��A�N�e�B�u��Ԃł����s
	SetFontSize(32);								//�t�H���g�T�C�Y�ύX

	if (DxLib_Init() == -1) {						//�������Ɏ��s������I������

		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

//�Q�[���̏I������
void SystemMain::end() const {
	DxLib_End();									//Dx���C�u�����I������
}

//���C������
void SystemMain::main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!looper.loop()) {
			break;
		}
	}
}