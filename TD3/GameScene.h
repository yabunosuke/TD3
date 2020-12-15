#pragma once
#include "AbstractScene.h"
#include "Camera.h"

class GameScene : public AbstractScene
{
public:
	const static char *StageTag;

	GameScene(IoChangedListener *impl, const Parameter &parameter);
	~GameScene();
	void init() override;
	void finalize() override;
	void update() override;
	void draw() const override;

private:
	Camera camera;
	int _counter;
	int _slectTag;
};