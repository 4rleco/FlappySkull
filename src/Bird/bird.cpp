#include "bird.h"

namespace game
{
void moveBirdUp(Bird& bird);
void moveBirdDown(Bird& bird);

void initBird(Bird& bird)
{
    bird.pos = { 120, 240 };
    bird.speed = 20.0f;
    bird.radius = 50;
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
}

void drawBird(Bird bird)
{
    DrawCircleV(bird.pos, bird.radius, MAROON);
}
}