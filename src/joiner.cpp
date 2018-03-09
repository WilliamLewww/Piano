#include "joiner.h"

Joiner joiner;

void Joiner::initialize() {
	piano.generateKeys();
}

void Joiner::update(int elapsedTime) {
	piano.update();
}

void Joiner::draw() {
	piano.draw();
}