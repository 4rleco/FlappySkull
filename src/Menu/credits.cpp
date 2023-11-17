#include "credits.h"

#include "menu.h"

#include "raylib.h"

#include <string>


namespace game
{
	extern Button backButton;

	void printCredits()
	{
		std::string creditsText1 = "Game developed by Daniela Gonzalez";
		std::string creditsText2 = "and Joaquin Herrero Lendner";
		int creditsSize = 30;
	
		int creditsPosX = GetScreenWidth() / 2 - static_cast<int>((MeasureText(creditsText1.c_str(), creditsSize))) / 2;
		int creditsPosY = GetScreenHeight() / 2;

		updateBackButton(backButton);

		BeginDrawing();
		ClearBackground(GRAY);

		drawBackButton(backButton);
		DrawText(creditsText1.c_str(), static_cast<int>(creditsPosX), static_cast<int>(creditsPosY), creditsSize, ORANGE);
		DrawText(creditsText2.c_str(), static_cast<int>(creditsPosX) + 60, static_cast<int>(creditsPosY) + 60, creditsSize, ORANGE);
		EndDrawing();
	}
}