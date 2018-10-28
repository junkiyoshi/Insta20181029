#include "Particle.h"

Particle::Particle() {

	int x = (int)(ofRandom(ofGetWidth()) / 40) * 40;
	int y = (int)(ofRandom(ofGetHeight()) / 40) * 40;
	this->location = ofPoint(x, y);

	this->directions[0] = ofPoint(1, 0);
	this->directions[1] = ofPoint(-1, 0);
	this->directions[2] = ofPoint(0, 1);
	this->directions[3] = ofPoint(0, -1);

	this->color.setHsb(ofRandom(255), 230, 255);
	this->life = 255;
}

Particle::~Particle() {

}

void Particle::Upate() {

	if (ofGetFrameNum() % 40 == 0) {

		int r = ofRandom(4);
		this->direction = this->directions[r];

		if (this->location.x < 0) { this->direction = ofPoint(1, 0); }
		else if (this->location.x > ofGetWidth()) { this->direction = ofPoint(-1, 0); }

		if (this->location.y < 0) { this->direction = ofPoint(0, 1); }
		else if (this->location.y > ofGetHeight()) { this->direction = ofPoint(0, -1); }
	}

	this->location += this->direction * 2;
	this->logs.push_front(location);
	while (this->logs.size() > 60) { this->logs.pop_back(); }

	this->life -= 1;
}

void Particle::Draw() {

	ofSetColor(this->color, this->life);

	ofFill();
	ofDrawCircle(this->location, 8);

	ofNoFill();
	ofBeginShape();
	for (ofPoint& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}

bool Particle::IsDead() {

	return this->life < 0 ? true : false;
}