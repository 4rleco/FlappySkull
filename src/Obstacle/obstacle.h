#pragma once

#include "raylib.h"

namespace game
{
struct Obstacle
{
	int width;
	int height;
	Rectangle pos;
	float speed;
	Color color;
};

void initObstacle(Obstacle& obstacle);
void updateObstacle(Obstacle& obstacle);
void drawObstacle(Obstacle obstacle);
}