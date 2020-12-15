#include "GameScene.h"
#include "Player.h"
#include "WindowSize.h"

const char *GameScene::StageTag = "StageTag";      //ステージ決定用のパラメータ

GameScene::GameScene(IoChangedListener *impl, const Parameter &parameter)
    : AbstractScene(impl, parameter),
	camera(GetWinSize()) {
    _slectTag = parameter.get(StageTag);
    _counter = 0;
}

GameScene::~GameScene() {
}

void GameScene::init() {
    _counter = 0;
    camera.Initialize();
	//イニシャライズ処理
}

void GameScene::finalize() {
	//ファイナライズ処理
}

void GameScene::update() {
	//ゲームシーンアップデート
    _counter++;
}

void GameScene::draw() const {
    //ゲームシーンでの描画
}
