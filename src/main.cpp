#include "raylib.h"

#include <iostream>

#include "bird/bird.h"
#include "Obstacle/obstacle.h"

using namespace game;

int main()
{
    const int width = 640;
    const int height = 480;

    InitWindow(width, height, "Flappy Bird");
    Bird bird;
    Obstacle obstacle;

    initBird(bird);
    initObstacle(obstacle);

    while (!WindowShouldClose())
    {
        updateBird(bird);
        updateObstacle(obstacle, width, height);

        if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle.rect))
        {
            restartBird(bird);
            restartObstacle(obstacle, width, height);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawBird(bird);
        drawObstacle(obstacle);

        EndDrawing();
    }
    CloseWindow();
}