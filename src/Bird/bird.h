#pragma once

#include "raylib.h"

namespace game
{
struct Bird
{
    Vector2 pos;
    float speed;
    float radius;
    Color color;
};

void initBird(Bird& bird);
void updateBird(Bird& bird);
void drawBird(Bird bird);
}