#pragma once

#include "obstacle.h"

namespace game
{
	const int maxObstacles = 3;
	
	struct ObstacleManager
	{
		Obstacle obstacles[maxObstacles];

		int spaceBetweenObstacles;
	};

	void initObstacles(ObstacleManager& obstacleManager);
	void restartObstacles(ObstacleManager& obstacleManager);
	void drawObstacles(ObstacleManager obstacleManager);
}