#include "obstacle.h"

#include <time.h>
#include <iostream>

namespace game
{
	extern const int width;
	extern const int height;
	static int space = 90;

	void checkObstacleLimits(Obstacle& obstacle);
	float getRandomObstacleHeight();

	void initObstacle(Bird bird, Obstacle& obstacle)
	{
		initPipe(obstacle.pipeUp);
		initPipe(obstacle.pipeDown);

		obstacle.pipeUp.rect.height = getRandomObstacleHeight();
		
		if (obstacle.pipeUp.rect.height <= 0)
		{
			obstacle.pipeUp.rect.height = 0;
		}

		obstacle.pipeDown.rect.y += obstacle.pipeUp.rect.height + bird.radius + getBirdDiameter() + space;

		obstacle.speed = 85.0f;

		obstacle.givePoints = 5;

		obstacle.ofScreen = false;
	}

	void updateObstacle(Obstacle& obstacle)
	{
		obstacle.pipeUp.rect.x -= obstacle.speed * GetFrameTime();
		obstacle.pipeDown.rect.x -= obstacle.speed * GetFrameTime();

		checkObstacleLimits(obstacle);
	}

	void checkObstacleLimits(Obstacle& obstacle) // if the pipe is no longer on screen
	{
		if (obstacle.pipeUp.rect.x + obstacle.pipeUp.rect.width <= 0 &&
			obstacle.pipeDown.rect.x + obstacle.pipeDown.rect.width <= 0)
		{
			obstacle.ofScreen = true;
		}
	}

	float getRandomObstacleHeight()
	{
		return static_cast<float>(GetRandomValue(getBirdDiameter(), height - getBirdDiameter() - space));
	}
}