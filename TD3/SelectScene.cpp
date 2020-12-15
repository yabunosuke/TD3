#include "DxLib.h"
#include "SelectScene.h"
#include "UsersInput.h"
//セレクトシーンから移動できるシーンがあればここにinclude
#include "TestScene.h"
#include "GameScene.h"

SelectScene::SelectScene(IoChangedListener *impl, const Parameter &parameter)
    : AbstractScene(impl, parameter) {
}

void SelectScene::init()
{
}

void SelectScene::finalize()
{
}

void SelectScene::update() {
    InputUpdate();
    if (JustInput(KEY_INPUT_1)) {
        Parameter parameter;
        parameter.set(GameScene::StageTag,1);
        _implSceneChanged->onSceneChanged(Scenes::Game, parameter, false);
        //1を押すとパラメータ1をステージタグとして受け渡し
    }
    if (JustInput(KEY_INPUT_2)) {
        Parameter parameter;
        parameter.set(GameScene::StageTag, 2);
        _implSceneChanged->onSceneChanged(Scenes::Game, parameter, false);
        //2を押すとパラメータ2をステージタグとして受け渡し
    }
}

void SelectScene::draw() const {
    DrawStringF(0, 0, "セレクトシーンですけど\n1.ゲームチェック用\n2.パラメータチェック用\n3.2つをくっつけた奴です", GetColor(255, 255, 255));
}

void SelectScene::StageSelectUpdate()
{
	if(JustInput(KEY_INPUT_LEFT))
	{
		
	}
}
