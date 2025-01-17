#include "obstacleMangaer.h"

#include "Bird/bird.h"

namespace game
{
	void initObstacles(ObstacleManager& obstacleManager)
	{
		obstacleManager.spaceBetweenObstacles = 10;

		for (int i = 0; i < maxObstacles; i++)
		{
			obstacleManager.spaceBetweenObstacles += i * i-1;

			initObstacle(obstacleManager.obstacles[i], obstacleManager.spaceBetweenObstacles);
		}
	}

	void restartObstacles(ObstacleManager& obstacleManager)
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (obstacleManager.obstacles[i].ofScreen)
			{
				initObstacle(obstacleManager.obstacles[i], obstacleManager.spaceBetweenObstacles);
			}
		}
	}

	void drawObstacles(ObstacleManager obstacleManager)
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			DrawRectangle(static_cast<int>(obstacleManager.obstacles[i].pipeUp.rect.x), static_cast<int>(obstacleManager.obstacles[i].pipeUp.rect.y), static_cast<int>(obstacleManager.obstacles[i].pipeUp.rect.width), static_cast<int>(obstacleManager.obstacles[i].pipeUp.rect.height), obstacleManager.obstacles[i].pipeUp.color);
			DrawRectangle(static_cast<int>(obstacleManager.obstacles[i].pipeDown.rect.x), static_cast<int>(obstacleManager.obstacles[i].pipeDown.rect.y), static_cast<int>(obstacleManager.obstacles[i].pipeDown.rect.width), static_cast<int>(obstacleManager.obstacles[i].pipeDown.rect.height), obstacleManager.obstacles[i].pipeDown.color);
		}
	}
}