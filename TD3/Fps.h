#pragma once
#include <list>

using namespace std;

class Fps {
public:
	Fps();
	void wait();
	void draw() const;

private:
	list<int> _list;
	float _fps;
	unsigned _counter;		//���̒l�����ŃJ�E���g����

	void updateAverage();
	void regist();
	unsigned getWaitTime() const;
};

