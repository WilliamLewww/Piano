#pragma once
#include <bass.h>

class Audio {
private:
public:
	void initialize(HWND hwnd);
	void quit();

	void playSoundFile(const char* file);
};

extern Audio audio;