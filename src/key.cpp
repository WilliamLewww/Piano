#include "key.h"

Key::Key(Vector2 position, int width, int height) {
	this->position = position;
	this->width = width;
	this->height = height;
}

Key::Key(Vector2 position, int width, int height, int color[3]) {
	this->position = position;
	this->width = width;
	this->height = height;

	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

void Key::setKeyboardKey(SDL_Keycode keycode) {
	linkedKeyboardKey = keycode;
}

SDL_Keycode Key::getKeyboardKey() {
	return linkedKeyboardKey;
}

void Key::draw() {
	if (isPressed) {
		drawPressed();
	}
	else {
		drawReleased();
	}
}

void Key::drawPressed() {
	drawing.drawRect(position, width, height, pressColor);

	drawing.drawLine(position, position + Vector2(width, 0), pressColor);
	drawing.drawLine(position, position + Vector2(0, height), pressColor);
	drawing.drawLine(position + Vector2(width, height), position + Vector2(0, height), pressColor);
	drawing.drawLine(position + Vector2(width, height), position + Vector2(width, 0), pressColor);
}

void Key::drawReleased() {
	drawing.drawRect(position, width, height, color);

	drawing.drawLine(position, position + Vector2(width, 0), outlineColor);
	drawing.drawLine(position, position + Vector2(0, height), outlineColor);
	drawing.drawLine(position + Vector2(width, height), position + Vector2(0, height), outlineColor);
	drawing.drawLine(position + Vector2(width, height), position + Vector2(width, 0), outlineColor);
}