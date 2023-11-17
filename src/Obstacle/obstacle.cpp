#include "obstacle.h"

#include <time.h>

#include "Bird/bird.h"

namespace game
{
extern const int width;
extern const int height;
static int space = 90;

void checkObstacleLimits(Obstacle obstacle[], const int maxObstacles);
float getRandomObstacleHeight();

void initObstacle(Obstacle obstacle[], const int maxObstacles)
{
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < maxObstacles; i++)
	{
		obstacle[i].rect.width = 50;
		obstacle[i].speed = 85.0f;
		obstacle[i].color = RED;
		obstacle[i].rect.x = static_cast<float>(width);

		if (i % 2 == 0)  // the pair numbers from the array will be the upper pipes 
		{
			obstacle[i].rect.y = 0;
			obstacle[i].rect.height = getRandomObstacleHeight();
		}
		else
		{
			obstacle[i].rect.y = obstacle[i - 1].rect.height + getBirdDiameter() + space;
			obstacle[i].rect.height = height;
		}
	}
}

void updateObstacle(Obstacle obstacle[], const int maxObstacles)
{
	for (int i = 0; i < maxObstacles; i++)
	{
		checkObstacleLimits(obstacle, maxObstacles);
		obstacle[i].rect.x -= obstacle[i].speed * GetFrameTime();
	}
}

void drawObstacle(Obstacle obstacle[], const int maxObstacles)
{
	for (int i = 0; i < maxObstacles; i++)
	{
		DrawRectangle(static_cast<int>(obstacle[i].rect.x), static_cast<int>(obstacle[i].rect.y), static_cast<int>(obstacle[i].rect.width), static_cast<int>(obstacle[i].rect.height), obstacle[i].color);
	}
}

void restartObstacles(Obstacle obstacle[], const int maxObstacles)
{
	for (int i = 0; i < maxObstacles; i++)
	{
		obstacle[i].rect.x = static_cast<float>(width);

		if (i % 2 == 0)
		{
			obstacle[i].rect.height = getRandomObstacleHeight();
		}
		else
		{
			obstacle[i].rect.y = obstacle[i - 1].rect.height + getBirdDiameter() + space;
			obstacle[i].rect.height = height;
		}
	}
}

void checkObstacleLimits(Obstacle obstacle[], const int maxObstacles) // if the pipe is no longer on screen
{
	for (int i = 0; i < maxObstacles; i++)
	{
		if (obstacle[i].rect.x < 0)
		{
			restartObstacles(obstacle, maxObstacles);
		}
	}
}

float getRandomObstacleHeight()
{
	return static_cast<float>(GetRandomValue(getBirdDiameter(), height - getBirdDiameter() - space));
}
}