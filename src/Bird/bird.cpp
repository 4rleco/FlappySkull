#include "bird.h"

namespace game
{
void moveBirdUp(Bird& bird);
void moveBirdDown(Bird& bird);

void initBird(Bird& bird)
{
    bird.pos = { 120, 240 };
    bird.speed = 45.0f;
    bird.radius = 50;
    bird.center.x = bird.pos.x + bird.radius * 2;
    bird.center.y = bird.pos.y + bird.radius * 2;
    bird.color = YELLOW;
}

void moveBirdUp(Bird& bird)
{
    if (IsKeyDown(KEY_UP)) bird.pos.y -= bird.speed * GetFrameTime();
}

void moveBirdDown(Bird& bird)
{
    if (IsKeyDown(KEY_DOWN)) bird.pos.y += bird.speed * GetFrameTime();
}

void updateBird(Bird& bird)
{
    moveBirdUp(bird);
    moveBirdDown(bird);
    bird.center.x = bird.pos.x + bird.radius * 2;
    bird.center.y = bird.pos.y + bird.radius * 2;
}

void drawBird(Bird bird)
{
    DrawCircleV(bird.center, bird.radius, bird.color);
}

void restartBird(Bird& bird)
{
    bird.pos = { 120, 240 };
}
}