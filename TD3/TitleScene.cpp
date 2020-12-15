#include "DxLib.h"
#include "UsersInput.h"
#include "TitleScene.h"
//�^�C�g������ړ��ł���V�[��������΂�����include

TitleScene::TitleScene(IoChangedListener *impl, const Parameter &parameter)
    : AbstractScene(impl, parameter) {
	
}

void TitleScene::init()
{
}

void TitleScene::finalize()
{
}

void TitleScene::update() {
    InputUpdate();
    if(JustInput(KEY_INPUT_SPACE)) {
        Parameter parameter;
        _implSceneChanged->onSceneChanged(Scenes::Select, parameter, false);
    }
    if (JustInput(KEY_INPUT_UP)) {
        DxLib_End();
        exit(0);
    }

}

void TitleScene::draw() const {
    DrawStringF(0, 0, "�^�C�g���ł�����\nspace��������select��\n��������ƏI�����܂�����", GetColor(255, 255, 255));
}
