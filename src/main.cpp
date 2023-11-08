#include "raylib.h"

#include "bird/bird.h"
#include "Obstacle/obstacle.h"

using namespace game;

int main()
{
    const int width = 640;
    const int height = 480;
    const int fontSize = 30;
    Color fontColor = RED;

    InitWindow(width, height, "Flappy Bird");
    Bird bird;
    Obstacle obstacle;

    initBird(bird);
    initObstacle(obstacle);

    while (!WindowShouldClose())
    {
        updateBird(bird, height);
        updateObstacle(obstacle, width, height);

        if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle.rect))
        {
            restartBird(bird);
            restartObstacle(obstacle, width, height);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("v 0.1 ", width - MeasureText("v 0.1 ", fontSize), 
                 height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.1 ", fontSize, 0).y), fontSize, fontColor);
        drawBird(bird);
        drawObstacle(obstacle);

        EndDrawing();
    }
    CloseWindow();
}