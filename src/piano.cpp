#include "piano.h"

void Piano::update() {

}

void Piano::draw() {
	for (Key key : whiteKeys) {
		key.draw();
	}

	for (Key key : blackKeys) {
		key.draw();
	}
}

void Piano::generateKeys() {
	generateWhiteKeys(Vector2(configuration.getScreenWidth() / 17, 30), configuration.getScreenWidth() / 17, configuration.getScreenHeight() / 5);
	generateBlackKeys(Vector2(configuration.getScreenWidth() / 17, 30), configuration.getScreenWidth() / 17, configuration.getScreenHeight() / 5);
}

void Piano::generateWhiteKeys(Vector2 position, int width, int height) {
	for (int x = 0; x < 15; x++) {
		whiteKeys.emplace_back(position + Vector2(width * x, 0), width, height);
	}
}

void Piano::generateBlackKeys(Vector2 position, int width, int height) {
	int colorBlack[3] = { 0, 0, 0 };
	blackKeys.emplace_back(position + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);

	blackKeys.emplace_back(position + Vector2(width * 3, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 4, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 5, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);

	blackKeys.emplace_back(position + Vector2(width * 7, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 8, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);

	blackKeys.emplace_back(position + Vector2(width * 10, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 11, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 12, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
}