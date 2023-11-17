#include "menu.h"

namespace game
{
	CurrentScreen currentScreen = MENU;
	static const int fontSize = 20;
	static Color fontColor = RED;

	void printVersion();
	void drawButton(Button button);
	bool isMouseOverButton(Button button);
	bool isButtonClicked(Button& button);

	void initButtons(Button& playButton, Button& creditsButton, Button& exitButton, Button& backButton)
	{
		float buttonWidth = 200.f;
		float buttonHeight = 40.f;
		int offsetX = 100;
		int firstButtonOffsetY = -50;
		int secondButtonOffsetY = 10;
		int thirdButtonOffsetY = 70;

		playButton = { {static_cast<float>(width) / 2 - offsetX, static_cast<float>(height) / 2 + firstButtonOffsetY,
						buttonWidth, buttonHeight}, "Play", false };

		creditsButton = { {static_cast<float>(width) / 2 - offsetX,  static_cast<float>(height) / 2 + secondButtonOffsetY,
						   buttonWidth, buttonHeight}, "Credits", false };

		exitButton = { {static_cast<float>(width) / 2 - offsetX,  static_cast<float>(height) / 2 + thirdButtonOffsetY,
						buttonWidth, buttonHeight}, "Exit", false };

		backButton = { { 10, 10, 40, 40 }, "<-", false };
	}

	void drawButtons(Button playButton, Button creditsButton, Button exitButton)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		drawButton(playButton);
		drawButton(creditsButton);
		drawButton(exitButton);

		printVersion();

		EndDrawing();
	}

	void drawBackButton(Button backButton)
	{
		if (currentScreen != MENU) drawButton(backButton);
	}

	void updateMenu(Button& playButton, Button& creditsButton, Button& exitButton)
	{
		if (isButtonClicked(playButton)) currentScreen = PLAY;
		if (isButtonClicked(creditsButton)) currentScreen = CREDITS;
		if (isButtonClicked(exitButton)) currentScreen = EXIT;
	}

	void updateBackButton(Button backButton)
	{
		if (isButtonClicked(backButton) && currentScreen != MENU) currentScreen = MENU;
	}

	void printVersion()
	{
		DrawText("v 0.2 ", width - MeasureText("v 0.2 ", fontSize),
			height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.2 ", fontSize, 0).y), fontSize, fontColor);
	}

	void drawButton(Button button)
	{
		int offset = 10;

		DrawRectangleRec(button.bounds, BLACK);
		DrawText(button.text.c_str(), static_cast<int>(button.bounds.x + offset), static_cast<int>(button.bounds.y + offset), fontSize, WHITE);

		if (isMouseOverButton(button))
		{
			DrawRectangleRec(button.bounds, WHITE);
			DrawText(button.text.c_str(), static_cast<int>(button.bounds.x + offset), static_cast<int>(button.bounds.y + offset), fontSize, BLACK);
		}
	}

	bool isMouseOverButton(Button button)
	{
		return CheckCollisionPointRec(GetMousePosition(), button.bounds);
	}

	bool isButtonClicked(Button& button)
	{
		bool result = false;

		if (isMouseOverButton(button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			result = true;
		}

		button.clicked = result;
		return result;
	}
}