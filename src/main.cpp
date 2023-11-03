#include "raylib.h"

#include "bird/bird.h"

using namespace game;

int main()
{
    const int width = 640;
    const int height = 480;

    InitWindow(width, height, "Flappy Bird");
    Bird bird;

    initBird(bird);

    while (!WindowShouldClose())
    {
        updateBird(bird);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawBird(bird);

        EndDrawing();
    }
    CloseWindow();
}