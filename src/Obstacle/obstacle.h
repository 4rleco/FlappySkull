#pragma once

#include "raylib.h"

namespace game
{
	struct Obstacle
	{
		Rectangle rect;
		float speed;
		int givePoints;
		Color color;
	};

	void initObstacle(Obstacle obstacle[], const int maxObstacles);
	void updateObstacle(Obstacle obstacle[], const int maxObstacles);
	void drawObstacle(Obstacle obstacle[], const int maxObstacles);
}