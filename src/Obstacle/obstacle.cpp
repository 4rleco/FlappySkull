#include "obstacle.h"

namespace game
{
void initObstacle(Obstacle& obstacle)
{
	float sceenWidth = static_cast<float>(GetScreenWidth());
	float sceenHeight = static_cast<float>(GetScreenHeight());
	int offset = 10;

	obstacle.width = 50;
	obstacle.height = 100;
	obstacle.pos = { sceenWidth - offset - obstacle.width, sceenHeight / 2 - obstacle.pos.y / 2};
	obstacle.speed = 10.0f;
	obstacle.color = RED;
}

void updateObstacle(Obstacle& obstacle)
{
	obstacle.pos.x -= obstacle.speed * GetFrameTime();
}

void drawObstacle(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, obstacle.height, obstacle.color);
}
}