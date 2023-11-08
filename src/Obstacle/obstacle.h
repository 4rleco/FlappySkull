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

void initObstacle(Obstacle& obstacle);
void updateObstacle(Obstacle& obstacle, float screenWidth, float screenHeight);
void drawObstacle(Obstacle obstacle);
void restartObstacle(Obstacle& obstacle, float screenWidth, float screenHeight);
}