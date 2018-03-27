#include "piano.h"

void Piano::update() {
	for (Scale &scale : scales) {
		scale.update();
	}
}

void Piano::draw() {
	for (Scale scale : scales) {
		scale.draw();
	}
}

void Piano::generateScale(const char *file, bool eighth, Vector2 position, int width, int height) {
	scales.emplace_back();
	scales[scales.size() - 1].setEighth(eighth);
	scales[scales.size() - 1].setFile(file);
	scales[scales.size() - 1].initialize(position, width, height);
}