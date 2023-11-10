#pragma once

#include "raylib.h"

namespace game
{
struct Bird
{
    Vector2 pos;
    Vector2 center;
    float jumpForce;
    float radius;
    float gravity;
    float velocity;
    Color color;
};

void initBird(Bird& bird);
void updateBird(Bird& bird, int screenHeight);
void drawBird(Bird bird);
void restartBird(Bird& bird);
}