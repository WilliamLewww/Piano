#include "joiner.h"

Joiner joiner;

void Joiner::initialize() {
	strcpy(guiFile, "c-3.wav");

	guiPositionX = configuration.getScreenWidth() / 17;
	guiPositionY = 30;
	guiWidth = configuration.getScreenWidth() / 17;
	guiHeight = configuration.getScreenHeight() / 5;
}

void Joiner::update(int elapsedTime) {
	ImGui::SetNextWindowSizeConstraints(ImVec2(300, 200), ImVec2(300, 200));
	ImGui::Begin("Test");
	ImGui::InputText("File Name", guiFile, IM_ARRAYSIZE(guiFile));
	ImGui::InputInt("X-Coordinate", &guiPositionX);
	ImGui::InputInt("Y-Coordinate", &guiPositionY);
	ImGui::InputInt("Width", &guiWidth);
	ImGui::InputInt("Height", &guiHeight);
	if (ImGui::Button("Generate")) {
		piano.generateScale(guiFile, true, Vector2(guiPositionX, guiPositionY), guiWidth, guiHeight);
	}

	ImGui::Spacing();
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	
	ImGui::End();

	piano.update();
}

void Joiner::draw() {
	piano.draw();
}