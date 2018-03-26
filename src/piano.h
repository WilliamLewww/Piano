#pragma once
#include <vector>
#include "core\configuration.h"
#include "core\vector2.h"
#include "key.h"
#include "scale.h"

class Piano {
private:
	Scale scale;
public:
	void generateScale();
	void update();
	void draw();
};