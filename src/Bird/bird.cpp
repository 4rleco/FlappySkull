#include "bird.h"

namespace game
{
void moveBirdUp(Bird& bird);
void moveBirdDown(Bird& bird);
void checkBirdScreenLimits(Bird& bird, int screenHeight);

void initBird(Bird& bird)
{
    bird.pos = { 120, 240 };
    bird.speed = 45.0f;
    bird.radius = 50;
    bird.color = YELLOW;
}

void updateBird(Bird& bird, int screenHeight)
{
    bird.center.x = bird.pos.x + bird.radius;
    bird.center.y = bird.pos.y + bird.radius;
    moveBirdUp(bird);
    moveBirdDown(bird);
    checkBirdScreenLimits(bird, screenHeight);
}

void drawBird(Bird bird)
{
    DrawCircleV(bird.center, bird.radius, bird.color);
}

void restartBird(Bird& bird)
{
    bird.pos = { 120, 240 };
}

void moveBirdUp(Bird& bird)
{
    if (IsKeyDown(KEY_UP)) bird.pos.y -= bird.speed * GetFrameTime();
}

void moveBirdDown(Bird& bird)
{
    if (IsKeyDown(KEY_DOWN)) bird.pos.y += bird.speed * GetFrameTime();
}

void checkBirdScreenLimits(Bird& bird, int screenHeight)
{
    if (bird.pos.y < 0) bird.pos.y = 0;

    if (bird.pos.y + bird.radius * 2 > screenHeight)
    {
        bird.pos.y = static_cast<float>(screenHeight) - bird.radius * 2;
    }
}
}