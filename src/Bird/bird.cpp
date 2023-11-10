#include "bird.h"

#include <iostream>

namespace game
{
void moveBirdUp(Bird& bird);
//void moveBirdDown(Bird& bird);
void checkBirdScreenLimits(Bird& bird, int screenHeight);

void initBird(Bird& bird)
{
    bird.pos = { 120, 240 };
    bird.jumpForce = 250.f;
    bird.radius = 40.f;
    bird.gravity = 600.f;
    bird.velocity = 0.f;
    bird.color = YELLOW;
}

void updateBird(Bird& bird, int screenHeight)
{
    moveBirdUp(bird);
    checkBirdScreenLimits(bird, screenHeight);

    bird.velocity += bird.gravity * GetFrameTime();
    bird.pos.y += bird.velocity * GetFrameTime();

    bird.center.x = bird.pos.x + bird.radius;
    bird.center.y = bird.pos.y + bird.radius;
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
    if (IsKeyPressed(KEY_UP)) bird.velocity = -bird.jumpForce;
}

//void moveBirdDown(Bird& bird)
//{
//    if (IsKeyPressed(KEY_DOWN)) bird.pos.y += bird.jumpForce * GetFrameTime();
//}

void checkBirdScreenLimits(Bird& bird, int screenHeight)
{
    if (bird.pos.y < 0) bird.pos.y = 0;

    if (bird.pos.y + bird.radius * 2 > screenHeight)
    {
        bird.pos.y = static_cast<float>(screenHeight) - bird.radius * 2;
    }
}
}