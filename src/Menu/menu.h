#pragma once
#include "menu.h"

#include <iostream>

#include "raylib.h"

namespace game
{
	enum CurrentScreen { MENU, SINGLEPLAYER, MULTIPLAYER, PAUSE, CREDITS, EXIT };
	extern const int width;
	extern const int height;

	struct Button
	{
		Rectangle bounds;
		std::string text;
		bool clicked;
	};

	void initButtons(Button& onePlayerButton, Button& twoPlayerButton, Button& creditsButton, Button& exitButton, Button& backButton);
	void drawButtons(Button onePlayerButton, Button twoPlayerButton, Button creditsButton, Button exitButton);
	void drawBackButton(Button backButton);
	void updateMenu(Button& onePlayerButton, Button& twoPlayerButton, Button& creditsButton, Button& exitButton);
	void updateBackButton(Button backButton);
}