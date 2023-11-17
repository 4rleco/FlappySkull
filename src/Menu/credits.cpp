#include "credits.h"

#include "menu.h"

#include "raylib.h"

#include <string>


namespace game
{
	extern Button backButton;

	void printCredits()
	{
		std::string creditsText = "Game developed by Daniela Gonzalez";
		int creditsSize = 50;
	
		int creditsPosX = GetScreenWidth() / 2 - static_cast<int>((MeasureText(creditsText.c_str(), creditsSize))) / 2;
		int creditsPosY = GetScreenHeight() / 2;

		updateBackButton(backButton);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		drawBackButton(backButton);
		DrawText(creditsText.c_str(), static_cast<int>(creditsPosX), static_cast<int>(creditsPosY), creditsSize, ORANGE);
		EndDrawing();
	}
}