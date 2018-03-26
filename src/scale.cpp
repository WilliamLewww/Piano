#include "scale.h"

void Scale::setEighth(bool eighth) {
	this->eighth = eighth;
}

void Scale::setSecondary(bool secondary) {
	this->secondary = secondary;
}

void Scale::setFile(const char* file) {
	this->file = file;
}

void Scale::initialize(Vector2 position, int width, int height) {
	this->position = position;
	this->width = width;
	this->height = height;

	generateWhiteKeys();
	generateBlackKeys();
}

void Scale::generateWhiteKeys() {
	int keyCount = 8;

	if (eighth == false) { keyCount = 7; }

	for (int x = 0; x < keyCount; x++) {
		whiteKeys.emplace_back(position + Vector2(width * x, 0), width, height);
	}

	linkWhiteKeys();
}

void Scale::generateBlackKeys() {
	int colorBlack[3] = { 0, 0, 0 };
	blackKeys.emplace_back(position + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);

	blackKeys.emplace_back(position + Vector2(width * 3, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 4, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);
	blackKeys.emplace_back(position + Vector2(width * 5, 0) + Vector2(width * 3 / 4, 0), width / 2, height * 3 / 5, colorBlack);

	linkBlackKeys();
}

void Scale::linkWhiteKeys() {
	if (secondary) {
		whiteKeys[0].setKeyboardKey(SDLK_i);
		whiteKeys[0].createStream(file, 0);
		whiteKeys[1].setKeyboardKey(SDLK_o);
		whiteKeys[1].createStream(file, 2);
		whiteKeys[2].setKeyboardKey(SDLK_p);
		whiteKeys[2].createStream(file, 4);
		whiteKeys[3].setKeyboardKey(SDLK_x);
		whiteKeys[3].createStream(file, 5);
		whiteKeys[4].setKeyboardKey(SDLK_c);
		whiteKeys[4].createStream(file, 7);
		whiteKeys[5].setKeyboardKey(SDLK_v);
		whiteKeys[5].createStream(file, 9);
		whiteKeys[6].setKeyboardKey(SDLK_b);
		whiteKeys[6].createStream(file, 11);

		if (eighth) {
			whiteKeys[7].setKeyboardKey(SDLK_n);
			whiteKeys[7].createStream(file, 12);
		}
	}
	else {
		whiteKeys[0].setKeyboardKey(SDLK_q);
		whiteKeys[0].createStream(file, 0);
		whiteKeys[1].setKeyboardKey(SDLK_w);
		whiteKeys[1].createStream(file, 2);
		whiteKeys[2].setKeyboardKey(SDLK_e);
		whiteKeys[2].createStream(file, 4);
		whiteKeys[3].setKeyboardKey(SDLK_r);
		whiteKeys[3].createStream(file, 5);
		whiteKeys[4].setKeyboardKey(SDLK_t);
		whiteKeys[4].createStream(file, 7);
		whiteKeys[5].setKeyboardKey(SDLK_y);
		whiteKeys[5].createStream(file, 9);
		whiteKeys[6].setKeyboardKey(SDLK_u);
		whiteKeys[6].createStream(file, 11);

		if (eighth) {
			whiteKeys[7].setKeyboardKey(SDLK_i);
			whiteKeys[7].createStream(file, 12);
		}
	}
}

void Scale::linkBlackKeys() {
	if (secondary) {
		blackKeys[0].setKeyboardKey(SDLK_9);
		blackKeys[0].createStream(file, 1);
		blackKeys[1].setKeyboardKey(SDLK_0);
		blackKeys[1].createStream(file, 3);	
		blackKeys[2].setKeyboardKey(SDLK_d);
		blackKeys[2].createStream(file, 6);
		blackKeys[3].setKeyboardKey(SDLK_f);
		blackKeys[3].createStream(file, 8);
		blackKeys[4].setKeyboardKey(SDLK_g);
		blackKeys[4].createStream(file, 10);
	}
	else {
		blackKeys[0].setKeyboardKey(SDLK_2);
		blackKeys[0].createStream(file, 1);
		blackKeys[1].setKeyboardKey(SDLK_3);
		blackKeys[1].createStream(file, 3);	
		blackKeys[2].setKeyboardKey(SDLK_5);
		blackKeys[2].createStream(file, 6);
		blackKeys[3].setKeyboardKey(SDLK_6);
		blackKeys[3].createStream(file, 8);
		blackKeys[4].setKeyboardKey(SDLK_7);
		blackKeys[4].createStream(file, 10);
	}
}

void Scale::update() {
	for (SDL_Keycode keycode : input.returnKeyList()) {
		for (Key &key : whiteKeys) {
			if (keycode == key.getKeyboardKey()) {
				if (std::find(pressedKeys.begin(), pressedKeys.end(), &key) == pressedKeys.end()) {
					pressedKeys.push_back(&key);
				}
			}
		}
		for (Key &key : blackKeys) {
			if (keycode == key.getKeyboardKey()) {
				if (std::find(pressedKeys.begin(), pressedKeys.end(), &key) == pressedKeys.end()) {
					pressedKeys.push_back(&key);
				}
			}
		}
	}

	for (int x = 0; x < pressedKeys.size(); x++) {
		pressedKeys[x]->handlePress();

		if (!pressedKeys[x]->checkPress()) {
			pressedKeys.erase(pressedKeys.begin() + x);
		}
	}
}

void Scale::draw() {
	for (Key key : whiteKeys) {
		key.draw();
	}

	for (Key key : blackKeys) {
		key.draw();
	}
}