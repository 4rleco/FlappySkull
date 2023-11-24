#pragma once

#include "pipe.h"
#include "Bird/bird.h"

#include "raylib.h"

namespace game
{
	struct Obstacle
	{
		Pipe pipeUp;
		Pipe pipeDown;
		float speed;
		int givePoints;
		bool ofScreen;
	};

	void initObstacle(Bird bird, Obstacle& obstacle);
	void updateObstacle(Obstacle& obstacle);
	void drawObstacle(Obstacle obstacle);
}