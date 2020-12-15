#include "UsersInput.h"
#include"DxLib.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

const static int KEY_NUM = 256;
static char keys[KEY_NUM];		//�ŐV�̃L�[�{�[�h���p
static char oldkeys[KEY_NUM];	//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

void InputUpdate()
{
	//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < KEY_NUM; i++)
		oldkeys[i] = keys[i];

	//�ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

bool JustInput(int KeyCode)
{
	if (keys[KeyCode] && !oldkeys[KeyCode])return true;
	else return false;
}

bool Input(int KeyCode)
{
	if (keys[KeyCode])return true;
	else return false;
}

bool JustOut(int KeyCode)
{
	if (!keys[KeyCode] && oldkeys[KeyCode])return true;
	else return false;
}
