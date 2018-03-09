#include "audio.h"

Audio audio;

void Audio::initialize(HWND hwnd) {
	BASS_Init(-1, 44100, 0, hwnd, NULL);
	playSoundFile("c.wav");
}

void Audio::playSoundFile(const char* file) {
	HSTREAM stream = BASS_StreamCreateFile(FALSE, file, 0, 0, 0);
	BASS_ChannelPlay(stream, false);
}

void Audio::quit() {
	BASS_Free();
}