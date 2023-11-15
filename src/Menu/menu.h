#pragma once
#include "menu.h"

#include <iostream>

#include "raylib.h"

namespace game
{
enum CurrentScreen { MENU, PLAY, PAUSE, CREDITS, EXIT };

struct Button 
{
    Rectangle bounds;
    std::string text;
    bool clicked;
};

void initButtons(Button& playButton, Button& creditsButton, Button& exitButton, Button& backButton);
void drawButtons(Button playButton, Button creditsButton, Button exitButton);
void drawBackButton(Button backButton);
void updateMenu(Button& playButton, Button& creditsButton, Button& exitButton);
void updateBackButton(Button backButton);
}