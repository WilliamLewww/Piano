#pragma once
#include "core\vector2.h"
#include "key.h"

class Scale {
private:
	Vector2 position;
	int width, height;

	bool eighth, secondary;
	const char* file;

	std::vector<Key> whiteKeys;
	std::vector<Key> blackKeys;

	std::vector<Key*> pressedKeys;

	void generateWhiteKeys();
	void generateBlackKeys();

	void linkWhiteKeys();
	void linkBlackKeys();
public:
	void setEighth(bool eighth);
	void setSecondary(bool secondary);
	void setFile(const char* file);

	void initialize(Vector2 position, int width, int height);
	void update();
	void draw();
};