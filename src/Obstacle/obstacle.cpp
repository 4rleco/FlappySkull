#include "obstacle.h"

#include <time.h>

#include "Bird/bird.h"

namespace game
{
extern const int width;
extern const int height;

void checkObstacleLimits(Obstacle& obstacle, bool isTop); 
float getRandomObstacleHeight(bool isTop);

void initObstacle(Obstacle& obstacle, bool isTop)
{
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));

	obstacle.rect.width = 50;
	obstacle.speed = 85.0f;
	obstacle.color = RED;
	obstacle.rect.x = static_cast<float>(width);

	if (isTop)
	{
		obstacle.rect.height = getRandomObstacleHeight(true);
		obstacle.rect.y = height - obstacle.rect.height / 2;
	}
	else
	{
		obstacle.rect.height = getRandomObstacleHeight(false);
		obstacle.rect.y = 0;
	}
}

void updateObstacle(Obstacle& obstacle, bool isTop)
{
	checkObstacleLimits(obstacle, isTop);
	obstacle.rect.x -= obstacle.speed * GetFrameTime();
}

void drawObstacle(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.rect.x), static_cast<int>(obstacle.rect.y), static_cast<int>(obstacle.rect.width), static_cast<int>(obstacle.rect.height), obstacle.color);
}

void restartObstacle(Obstacle& obstacle, bool isTop)
{
	obstacle.rect.x = static_cast<float>(width);

	if (isTop)
	{
		obstacle.rect.height = getRandomObstacleHeight(true);
		obstacle.rect.y = height - obstacle.rect.height / 2;
	}
	else
	{
		obstacle.rect.height = getRandomObstacleHeight(false);
		obstacle.rect.y = 0;
	}

}

void checkObstacleLimits(Obstacle& obstacle, bool isTop)
{
	if (obstacle.rect.x < 0)
	{
		restartObstacle(obstacle, isTop);
	}
}

float getRandomObstacleHeight(bool isTop)
{
	if (isTop)
	{
		return static_cast<float>(0, getBirdDiameter());
	}
	else
	{
		return static_cast<float>(GetRandomValue(getBirdDiameter(), static_cast<int>(height)));
	}
}
}