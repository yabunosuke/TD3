#pragma once
#include"Vector2.h"

class Particle
{
public:
	const enum BLEND_MODE {
		ALPHA, ADD
	};

protected:
	static const int BLEND[2];

	int _maxSpeed;			//�ő啬�o���x
	Vector2<float> _pos;	//���W
	Vector2<float> _vel;	//�ړ���
	float _size;			//�T�C�Y
	int _pal;				//�s�����x
	int _palChange;

	BLEND_MODE _blendMode;

	bool _isAliveFlag;

public:
	virtual ~Particle() {};

	virtual void Initialize() = 0;
	virtual void Update();
	virtual void Draw() = 0;

	virtual void Emit(Vector2<float> initPos) = 0;

	bool GetAlive() { return _isAliveFlag; }
};

//�T�C�Y�ύX�Ȃ��A�l�p��`��,�����Ȃ�
class BoxParticle :public Particle
{
	int _red;
	int _green;
	int _blue;

public:
	BoxParticle(int initSize, int maxEmitSpeed, int palChangeRate, BLEND_MODE blend, int r, int g, int b);
	~BoxParticle() {};

	virtual void Initialize()override;
	virtual void Draw()override;
	virtual void Emit(Vector2<float> initPos)override;
};

//�T�C�Y�ύX�Ȃ��A�l�p��`��,��������
class FallBoxParticle :public BoxParticle
{
	float _gravity;
	float _fallVel;

public:
	FallBoxParticle(int initSize, int maxEmitSpeed, int palChangeRate, BLEND_MODE blend, int r, int g, int b, float gravity);
	virtual void Update()override;
	virtual void Emit(Vector2<float>initPos)override;
};