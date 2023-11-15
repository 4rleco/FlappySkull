#include "menu.h"

namespace game
{
MenuButtons menuButton = MENU;

void drawButton(Button button);
bool isMouseOverButton(Button button);
bool isButtonClicked(Button& button);

void initButtons(Button& playButton, Button& creditsButton, Button& exitButton)
{
    playButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100, static_cast<float>(GetScreenHeight()) / 2 - 50, 200, 40}, "Play", false };
    creditsButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 10, 200, 40}, "Credits", false };
    exitButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 70, 200, 40}, "Exit", false };
}

void drawButtons(Button playButton, Button creditsButton, Button exitButton)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    drawButton(playButton);
    drawButton(creditsButton);
    drawButton(exitButton);

    EndDrawing();
}

void updateMenu(Button& playButton, Button& creditsButton, Button& exitButton)
{
    if (isButtonClicked(playButton)) menuButton = PLAY;
    if (isButtonClicked(creditsButton)) menuButton = CREDITS;
    if (isButtonClicked(exitButton)) menuButton = EXIT;
}

void drawButton(Button button) {

    DrawRectangleRec(button.bounds, BLACK);
    DrawText(button.text, static_cast<int>(button.bounds.x + 10), static_cast<int>(button.bounds.y + 10), 20, WHITE);
   
    if (isMouseOverButton(button))
    {
        DrawRectangleRec(button.bounds, WHITE);
        DrawText(button.text, static_cast<int>(button.bounds.x + 10), static_cast<int>(button.bounds.y + 10), 20, BLACK);
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