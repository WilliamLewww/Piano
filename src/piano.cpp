#include "piano.h"

void Piano::update() {
	scale.update();
}

void Piano::draw() {
	scale.draw();
}

void Piano::generateScale() {
	scale.setEighth(true);
	scale.setFile("c-3.wav");

	scale.initialize(Vector2(configuration.getScreenWidth() / 17, 30), configuration.getScreenWidth() / 17, configuration.getScreenHeight() / 5);
}