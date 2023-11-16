#include "menu.h"

namespace game
{
CurrentScreen currentScreen = MENU;
static const int fontSize = 30;
static Color fontColor = RED;

void printVersion();
void drawButton(Button button);
bool isMouseOverButton(Button button);
bool isButtonClicked(Button& button);

void initButtons(Button& playButton, Button& creditsButton, Button& exitButton, Button& backButton)
{
    playButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100, static_cast<float>(GetScreenHeight()) / 2 - 50, 200, 40}, "Play", false };
    creditsButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 10, 200, 40}, "Credits", false };
    exitButton = { {static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 70, 200, 40}, "Exit", false };

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
    if(currentScreen != MENU) drawButton(backButton);
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
    DrawText("v 0.2 ", width -MeasureText("v 0.2 ", fontSize),
    height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.2 ", fontSize, 0).y), fontSize, fontColor);
}

void drawButton(Button button) 
{
    DrawRectangleRec(button.bounds, BLACK);
    DrawText(button.text.c_str(), static_cast<int>(button.bounds.x + 10), static_cast<int>(button.bounds.y + 10), 20, WHITE);
   
    if (isMouseOverButton(button))
    {
        DrawRectangleRec(button.bounds, WHITE);
        DrawText(button.text.c_str(), static_cast<int>(button.bounds.x + 10), static_cast<int>(button.bounds.y + 10), 20, BLACK);
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