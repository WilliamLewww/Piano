#include "piano.h"

void Piano::update() {
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

	linkWhiteKeys();
}

void Piano::linkWhiteKeys() {
	whiteKeys[0].setKeyboardKey(SDLK_q);
	whiteKeys[1].setKeyboardKey(SDLK_w);
	whiteKeys[2].setKeyboardKey(SDLK_e);
	whiteKeys[3].setKeyboardKey(SDLK_r);
	whiteKeys[4].setKeyboardKey(SDLK_t);
	whiteKeys[5].setKeyboardKey(SDLK_y);
	whiteKeys[6].setKeyboardKey(SDLK_u);
	whiteKeys[7].setKeyboardKey(SDLK_i);
	whiteKeys[8].setKeyboardKey(SDLK_o);
	whiteKeys[9].setKeyboardKey(SDLK_p);
	whiteKeys[10].setKeyboardKey(SDLK_x);
	whiteKeys[11].setKeyboardKey(SDLK_c);
	whiteKeys[12].setKeyboardKey(SDLK_v);
	whiteKeys[13].setKeyboardKey(SDLK_b);
	whiteKeys[14].setKeyboardKey(SDLK_n);
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

	linkBlackKeys();
}

void Piano::linkBlackKeys() {
	blackKeys[0].setKeyboardKey(SDLK_2);
	blackKeys[1].setKeyboardKey(SDLK_3);
	blackKeys[2].setKeyboardKey(SDLK_5);
	blackKeys[3].setKeyboardKey(SDLK_6);
	blackKeys[4].setKeyboardKey(SDLK_7);
	blackKeys[5].setKeyboardKey(SDLK_9);
	blackKeys[6].setKeyboardKey(SDLK_0);
	blackKeys[7].setKeyboardKey(SDLK_d);
	blackKeys[8].setKeyboardKey(SDLK_f);
	blackKeys[9].setKeyboardKey(SDLK_g);
}