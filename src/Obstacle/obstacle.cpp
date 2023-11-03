#include "obstacle.h"

#include <time.h>

namespace game
{
void checkObstacleLimits(Obstacle& obstacle, float screenWidth, float screenHeight);

void initObstacle(Obstacle& obstacle)
{
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));
	float sceenWidth = static_cast<float>(GetScreenWidth());
	float sceenHeight = static_cast<float>(GetScreenHeight());
	int offset = 10;

	obstacle.width = 50;
	obstacle.height = 100;
	obstacle.pos = { sceenWidth - offset - obstacle.width, sceenHeight / 2 - obstacle.pos.y / 2};
	obstacle.speed = 65.0f;
	obstacle.color = RED;
}

void updateObstacle(Obstacle& obstacle, float screenWidth, float screenHeight)
{
	checkObstacleLimits(obstacle, screenWidth, screenHeight);
	obstacle.pos.x -= obstacle.speed * GetFrameTime();
}

void drawObstacle(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, obstacle.height, obstacle.color);
}

void checkObstacleLimits(Obstacle& obstacle, float screenWidth, float screenHeight)
{
	if (obstacle.pos.x < 0) obstacle.pos = { screenWidth,  static_cast<float>(GetRandomValue(0, static_cast<int>(screenHeight) - obstacle.height)) };
}
}