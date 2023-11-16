#pragma once

#include "raylib.h"

namespace game
{
struct Obstacle
{
	Rectangle rect;
	float speed;
	Color color;
};

void initObstacle(Obstacle& obstacle, bool isTop);
void updateObstacle(Obstacle& obstacle, bool isTop);
void drawObstacle(Obstacle obstacle);
void restartObstacle(Obstacle& obstacle, bool isTop);
}