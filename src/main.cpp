#include "raylib.h"

#include "Parallax/parallax.h"
#include "bird/bird.h"
#include "Obstacle/obstacle.h"

using namespace game;

int main()
{
    const int width = 1024;
    const int height = 768;
    const int fontSize = 30;
    Color fontColor = RED;

    InitWindow(width, height, "Flappy Bird");
    Bird bird;
    Obstacle obstacle;

    initParallax();
    initBird(bird);
    initObstacle(obstacle);

    while (!WindowShouldClose())
    {
        updateParallax();
        updateBird(bird);
        updateObstacle(obstacle, width, height);

        if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle.rect) || 
            checkBirdTouchGround(bird, height))
        {
            restartParallax();
            restartBird(bird);
            restartObstacle(obstacle, width, height);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawParallax();
        DrawText("v 0.1 ", width - MeasureText("v 0.1 ", fontSize), 
                 height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.1 ", fontSize, 0).y), fontSize, fontColor);
        drawBird(bird);
        drawObstacle(obstacle);

        EndDrawing();
    }
    deinitParallax();
    CloseWindow();
}