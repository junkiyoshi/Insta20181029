#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	void Upate();
	void Draw();

	bool IsDead();

private:

	ofPoint location;
	ofPoint direction;
	ofPoint directions[4];
	std::deque<ofPoint> logs;
	ofColor color;
	float life;
};