#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(1.5);

	for (int i = 0; i < 10; i++) { this->particles.push_back(Particle()); }
}
//--------------------------------------------------------------
void ofApp::update() {

	if (ofRandom(100) < 25) {

		this->particles.push_back(Particle());
	}

	for (int i = this->particles.size() - 1; i >= 0; i--) {

		if (this->particles[i].IsDead()) {

			this->particles.erase(this->particles.begin() + i);
		}
	}

	for (Particle& particle : particles) { particle.Upate(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (Particle& particle : particles) { particle.Draw(); }
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}