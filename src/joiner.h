#pragma once
#include "core\configuration.h"
#include "piano.h"

class Joiner {
private:
	Piano piano;
public:
	void initialize();
	void draw();
	void update(int elapsedTime);
};

extern Joiner joiner;