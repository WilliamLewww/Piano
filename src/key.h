#pragma once
#include "core\input.h"
#include "core\drawing.h"
#include "core\vector2.h"
#include "core\audio.h"

class Key {
private:
	Vector2 position;
	int width, height;

	int stream;

	SDL_Keycode linkedKeyboardKey;

	int color[3] = { 255, 255, 255 };
	int outlineColor[3] = { 0, 0, 0 };
	int pressColor[3] = { 255, 0, 0 };

	bool isPressed = 0;

	void drawPressed();
	void drawReleased();
public:
	Key(Vector2 position, int width, int height);
	Key(Vector2 position, int width, int height, int color[3]);

	void createStream(const char* note, float semitone);

	void setKeyboardKey(SDL_Keycode keycode);
	SDL_Keycode getKeyboardKey();

	bool checkPress();
	void handlePress();
	void draw();
};