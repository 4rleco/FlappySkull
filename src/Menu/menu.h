#pragma once
#include "menu.h"

#include "raylib.h"

namespace game
{
enum MenuButtons { MENU, PLAY, PAUSE, CREDITS, EXIT };

struct Button 
{
    Rectangle bounds;
    const char* text;
    bool clicked;
};

void initButtons(Button& playButton, Button& creditsButton, Button& exitButton);
void drawButtons(Button playButton, Button creditsButton, Button exitButton);
void updateMenu(Button& playButton, Button& creditsButton, Button& exitButton);
}