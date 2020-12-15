#pragma once
#include "IoChangedListener.h"
#include "Parameter.h"

class IoChangedListener;

class AbstractScene {
protected:	//�h���N���X�̂݃A�N�Z�X�\
	IoChangedListener *_implSceneChanged;
public:
	AbstractScene(IoChangedListener *impl, const Parameter &parameter);
	virtual ~AbstractScene() = default;
	virtual void init() = 0;
	virtual void finalize() = 0;
	virtual void update() = 0;
	virtual void draw() const = 0;

};

