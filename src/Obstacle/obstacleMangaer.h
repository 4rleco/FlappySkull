#pragma once

#include "obstacle.h"

namespace game
{
	const int maxObstacles = 3;
	
	struct ObstacleManager
	{
		Obstacle obstacles[maxObstacles];
	};

	void initObstacles(Bird bird, ObstacleManager& obstacleManager);
	void restartObstacles(Bird bird, ObstacleManager& obstacleManager);
	void drawObstacles(ObstacleManager obstacleManager);
}