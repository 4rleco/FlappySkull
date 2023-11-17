#include "obstacle.h"

#include "Bird/bird.h"

#include <time.h>

namespace game
{
	extern const int width;
	extern const int height;
	static int space = 90;
	static int spaceBetweenObstacles = 3;

	void restartObstacle(Obstacle& obstacle, int obstacleNumber, int prevoiusObstacleWidth, int previiousObstacleHeight, int previousObstacleX);
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

			if (i % 2 == 0)  // the pair numbers from the array will be the upper pipes 
			{
				obstacle[i].rect.x = static_cast<float>(width) + i * obstacle[i].rect.width * spaceBetweenObstacles;
				obstacle[i].rect.y = 0;
				obstacle[i].rect.height = getRandomObstacleHeight();
			}
			else
			{
				obstacle[i].rect.x = obstacle[i - 1].rect.x;
				obstacle[i].rect.y = obstacle[i - 1].rect.height + getBirdDiameter() + space;
				obstacle[i].rect.height = static_cast<float>(height);
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

	void restartObstacle(Obstacle& obstacle, int obstacleNumber, int prevoiusObstacleWidth, int previiousObstacleHeight, int previousObstacleX)
	{

		//obstacle[i].rect.x = static_cast<float>(width);
		/*	obstacle.rect.x = static_cast<float>(width) + i + 20*/;

		if (obstacleNumber % 2 == 0)
		{
			obstacle.rect.x = static_cast<float>(width) + obstacleNumber * prevoiusObstacleWidth * spaceBetweenObstacles;
			obstacle.rect.height = getRandomObstacleHeight();
		}
		else
		{
			obstacle.rect.x = static_cast<float>(previousObstacleX);
			obstacle.rect.y = static_cast<float>(previiousObstacleHeight + getBirdDiameter() + space);
			obstacle.rect.height = static_cast<float>(height);
		}

	}

	void checkObstacleLimits(Obstacle obstacle[], const int maxObstacles) // if the pipe is no longer on screen
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (obstacle[i].rect.x < 0)
			{
				restartObstacle(obstacle[i], i, static_cast<int>(obstacle[i - 1].rect.width), static_cast<int>(obstacle[i - 1].rect.height), static_cast<int>(obstacle[i - 1].rect.x));
			}
		}
	}

	float getRandomObstacleHeight()
	{
		return static_cast<float>(GetRandomValue(getBirdDiameter(), height - getBirdDiameter() - space));
	}
}