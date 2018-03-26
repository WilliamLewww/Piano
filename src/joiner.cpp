#include "joiner.h"

Joiner joiner;

void Joiner::initialize() {
	piano.generateKeys();
}

void Joiner::update(int elapsedTime) {

	ImGui::Begin("Test");
	ImGui::Text("Hello, world!");
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();

	piano.update();
}

void Joiner::draw() {
	piano.draw();
}