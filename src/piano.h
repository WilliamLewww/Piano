#pragma once
#include <vector>
#include "core\configuration.h"
#include "core\vector2.h"
#include "key.h"

class Piano {
private:
	std::vector<Key> whiteKeys;
	std::vector<Key> blackKeys;

	void generateWhiteKeys(Vector2 position, int width, int height);
	void generateBlackKeys(Vector2 position, int width, int height);
public:
	void update();
	void draw();
	
	void generateKeys();
};