#include "menu.h"

namespace game
{
	CurrentScreen currentScreen = MENU;
	static const int fontSize = 20;
	static const int titleFontSize = 60;
	static const int versionFontSize = 30;
	static Color fontColor = RED;
	static Color titleColor = RED;

	void printTitle();
	void printVersion();
	void drawButton(Button button);
	bool isMouseOverButton(Button button);
	bool isButtonClicked(Button& button);

	void initButtons(Button& onePlayerButton, Button& twoPlayerButton, Button& creditsButton, Button& exitButton, Button& backButton)
	{
		float buttonWidth = 200.f;
		float buttonHeight = 40.f;
		int offsetX = 100;
		int firstButtonOffsetY = -50;
		int secondButtonOffsetY = 10;
		int thirdButtonOffsetY = 70;
		int fourthButtonOffsetY = 130;

		onePlayerButton = { {static_cast<float>(width) / 2 - offsetX, static_cast<float>(height) / 2 + firstButtonOffsetY,
						buttonWidth, buttonHeight}, "SinglePlayer", false };

		twoPlayerButton = { {static_cast<float>(width) / 2 - offsetX, static_cast<float>(height) / 2 + secondButtonOffsetY,
						buttonWidth, buttonHeight}, "MultiPlayer", false };

		creditsButton = { {static_cast<float>(width) / 2 - offsetX,  static_cast<float>(height) / 2 + thirdButtonOffsetY,
						   buttonWidth, buttonHeight}, "Credits", false };

		exitButton = { {static_cast<float>(width) / 2 - offsetX,  static_cast<float>(height) / 2 + fourthButtonOffsetY,
						buttonWidth, buttonHeight}, "Exit", false };

		backButton = { { 980, 720, 40, 40 }, "<-", false };
	}

	void drawButtons(Button onePlayerButton, Button twoPlayerButton, Button creditsButton, Button exitButton)
	{
		BeginDrawing();
		ClearBackground(GRAY);

		printTitle();

		drawButton(onePlayerButton);
		drawButton(twoPlayerButton);
		drawButton(creditsButton);
		drawButton(exitButton);

		printVersion();

		EndDrawing();
	}

	void drawBackButton(Button backButton)
	{
		if (currentScreen != MENU) drawButton(backButton);
	}

	void updateMenu(Button& onePlayerButton, Button& twoPlayerButton, Button& creditsButton, Button& exitButton)
	{
		if (isButtonClicked(onePlayerButton)) currentScreen = SINGLEPLAYER;
		if (isButtonClicked(twoPlayerButton)) currentScreen = MULTIPLAYER;
		if (isButtonClicked(creditsButton)) currentScreen = CREDITS;
		if (isButtonClicked(exitButton)) currentScreen = EXIT;
	}

	void updateBackButton(Button backButton)
	{
		if (isButtonClicked(backButton) && currentScreen != MENU) currentScreen = MENU;
	}

	void printTitle()
	{
		DrawText("Flappy Skull", width - MeasureText("Flappy Skull", titleFontSize) * 2,
			height / 2 - (titleFontSize * 3), titleFontSize, titleColor);

	}

	void printVersion()
	{
		DrawText("v 0.3 ", width - MeasureText("v 0.3 ", versionFontSize),
			height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.3 ", versionFontSize, 0).y), versionFontSize, fontColor);
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