#include "credits.h"

#include <string>

#include "raylib.h"

namespace game
{
	void printCredits()
{
	std::string creditsText = "Game developed by Daniela Gonzalez";
	int creditsSize = 50;
	Vector2 creditsPos;
	creditsPos.x = GetScreenWidth() / 2 - static_cast<float>((MeasureText(creditsText.c_str(), creditsSize))) / 2;
	creditsPos.y = static_cast<float>(GetScreenHeight()) / 2;

	BeginDrawing();
	ClearBackground(RAYWHITE);

	DrawText(creditsText.c_str(), static_cast<int>(creditsPos.x), static_cast<int>(creditsPos.y), creditsSize, ORANGE);
	EndDrawing();
}
}