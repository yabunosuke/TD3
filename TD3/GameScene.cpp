#include "GameScene.h"
#include "Player.h"
#include "WindowSize.h"

const char *GameScene::StageTag = "StageTag";      //�X�e�[�W����p�̃p�����[�^

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
	//�C�j�V�����C�Y����
}

void GameScene::finalize() {
	//�t�@�C�i���C�Y����
}

void GameScene::update() {
	//�Q�[���V�[���A�b�v�f�[�g
    _counter++;
}

void GameScene::draw() const {
    //�Q�[���V�[���ł̕`��
}
