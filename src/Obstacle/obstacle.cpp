#include "obstacle.h"

#include <time.h>
#include <iostream>

namespace game
{
	extern const int width;
	extern const int height;
	static int space = 90;
	static int spaceBetweenObstacles = 3;

	void checkObstacleLimits(Obstacle obstacle);
	float getRandomObstacleHeight();

	void initObstacle(Bird bird, Obstacle& obstacle)
	{
		InitPipe(obstacle.pipeUp);
		InitPipe(obstacle.pipeDown);

		obstacle.pipeUp.rect.height = getRandomObstacleHeight();
		obstacle.pipeDown.rect.y = obstacle.pipeUp.rect.height + (bird.radius * 4);

		obstacle.speed = 85.0f;

		obstacle.givePoints = 10;

		obstacle.ofScreen = false;

		/*for (int i = 0; i < maxObstacles; i++)
		{
			obstacle[i].rect.width = 50;
			obstacle[i].speed = 85.0f;
			obstacle[i].givePoints = 10;
			obstacle[i].color = RED;

			if (i % 2 == 0)
			{
				obstacle[i].rect.x = static_cast<float>(width) + i * obstacle[i].rect.width * spaceBetweenObstacles;
				obstacle[i].rect.y = 0;

				do
				{
					obstacle[i].rect.height = getRandomObstacleHeight();

				} while (getRandomObstacleHeight() == obstacle[i].rect.height);
			}

			else
			{
				obstacle[i].rect.x = obstacle[i - 1].rect.x;
				obstacle[i].rect.y = obstacle[i - 1].rect.height + getBirdDiameter() + space;
				obstacle[i].rect.height = static_cast<float>(height);
			}
		}*/
	}

	void updateObstacle(Obstacle& obstacle)
	{
		obstacle.pipeUp.rect.x -= obstacle.speed * GetFrameTime();
		obstacle.pipeDown.rect.x -= obstacle.speed * GetFrameTime();

		checkObstacleLimits(obstacle);

		/*for (int i = 0; i < maxObstacles; i++)
		{
			obstacle[i].rect.x -= obstacle[i].speed * GetFrameTime();
			checkObstacleLimits(obstacle, maxObstacles);
		}*/
	}

	void drawObstacle(Obstacle obstacle)
	{
		DrawRectangle(static_cast<int>(obstacle.pipeUp.rect.x), static_cast<int>(obstacle.pipeUp.rect.y), static_cast<int>(obstacle.pipeUp.rect.width), static_cast<int>(obstacle.pipeUp.rect.height), obstacle.pipeUp.color);
		DrawRectangle(static_cast<int>(obstacle.pipeDown.rect.x), static_cast<int>(obstacle.pipeDown.rect.y), static_cast<int>(obstacle.pipeDown.rect.width), static_cast<int>(obstacle.pipeDown.rect.height), obstacle.pipeDown.color);
		/*for (int i = 0; i < maxObstacles; i++)
		{
			DrawRectangle(static_cast<int>(obstacle[i].rect.x), static_cast<int>(obstacle[i].rect.y), static_cast<int>(obstacle[i].rect.width), static_cast<int>(obstacle[i].rect.height), obstacle[i].color);
		}*/
	}

	void checkObstacleLimits(Obstacle obstacle) // if the pipe is no longer on screen
	{
		if (obstacle.pipeUp.rect.x + obstacle.pipeUp.rect.width <= 0 &&
			obstacle.pipeDown.rect.x + obstacle.pipeDown.rect.width <= 0)
		{
			obstacle.ofScreen = true;
		}

		/*for (int i = 0; i < maxObstacles; i++)
		{
			if (obstacle[i].rect.x + obstacle[i].rect.width < 0)
			{
				if (i == 0)
				{
					obstacle[i - 1] = obstacle[4];
				}

				restartObstacle(obstacle[i], i, static_cast<int>(obstacle[i - 1].rect.width), static_cast<int>(obstacle[i - 1].rect.height), static_cast<int>(obstacle[i - 1].rect.x));

				std::cout << i << std::endl;
			}
		}*/
	}

	float getRandomObstacleHeight()
	{
		return static_cast<float>(GetRandomValue(getBirdDiameter(), height - getBirdDiameter() - space));
	}
}