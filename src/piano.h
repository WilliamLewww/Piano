#pragma once
#include <vector>
#include "core\configuration.h"
#include "core\vector2.h"
#include "scale.h"

class Piano {
public:
	std::vector<Scale> scales;
	
	void generateScale(const char *file, bool eighth, Vector2 position, int width, int height);
	void update();
	void draw();
};