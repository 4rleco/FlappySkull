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

	obstacle.rect.width = 50;
	obstacle.rect.height = 100;
	obstacle.rect.x = sceenWidth - offset - obstacle.rect.width;
	obstacle.rect.y = sceenHeight / 2 - obstacle.rect.height / 2;
	obstacle.speed = 85.0f;
	obstacle.color = RED;
}

void updateObstacle(Obstacle& obstacle, float screenWidth, float screenHeight)
{
	checkObstacleLimits(obstacle, screenWidth, screenHeight);
	obstacle.rect.x -= obstacle.speed * GetFrameTime();
}

void drawObstacle(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.rect.x), static_cast<int>(obstacle.rect.y), static_cast<int>(obstacle.rect.width), static_cast<int>(obstacle.rect.height), obstacle.color);
}

void restartObstacle(Obstacle& obstacle, float screenWidth, float screenHeight)
{
	obstacle.rect.x = screenWidth;
	obstacle.rect.y = static_cast<float>(GetRandomValue(0, static_cast<int>(screenHeight) - static_cast<int>(obstacle.rect.height)));
}

void checkObstacleLimits(Obstacle& obstacle, float screenWidth, float screenHeight)
{
	if (obstacle.rect.x < 0)
	{
		obstacle.rect.x = screenWidth;
		obstacle.rect.y =  static_cast<float>(GetRandomValue(0, static_cast<int>(screenHeight) - static_cast<int>(obstacle.rect.height)));
	}
}
}