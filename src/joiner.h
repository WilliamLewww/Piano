#pragma once
#include "core\configuration.h"
#include "gui.h"
#include "piano.h"

class Joiner {
private:
	Piano piano;
	int guiPositionX, guiPositionY;
	int guiWidth, guiHeight;

	char guiFile[128];
public:
	void initialize();
	void draw();
	void update(int elapsedTime);
};

extern Joiner joiner;