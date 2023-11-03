#include "raylib.h"

int main()
{
    InitWindow(640, 480, "Flappy Bird");

    int posX = 320;
    int posY = 225;
    float radius = 90;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(posX, posY, radius, BLUE);

        EndDrawing();
    }

    CloseWindow();
}