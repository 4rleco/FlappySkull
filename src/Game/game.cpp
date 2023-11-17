#include "game.h"

#include "raylib.h"

#include "Parallax/parallax.h"
#include "Bird/bird.h"
#include "Obstacle/obstacle.h"
#include "Menu/menu.h"
#include "Menu/credits.h"

namespace game
{
extern CurrentScreen currentScreen;
const int maxObstacles = 6;
static Bird bird;
static Obstacle obstacle[maxObstacles];
static Button playButton;
static Button creditsButton;
static Button exitButton;
Button backButton;

const int width = 1024;
const int height = 768;

void initGame();
void updateGame();
void drawGame();
void deinitGame();

void gameLoop()
{
	initGame();

	initButtons(playButton, creditsButton, exitButton, backButton);

	while (!WindowShouldClose())
	{
		switch (currentScreen)
		{
		case MENU:
			updateMenu(playButton, creditsButton, exitButton);
			drawButtons(playButton, creditsButton, exitButton);
			break;
		case PLAY:
			updateGame();
			drawGame();
			break;
		case CREDITS:
			printCredits();
			break;
		case EXIT:
			return;
			break;
		default:
			break;
		}		
	}

	deinitGame();
}

void initGame()
{
	InitWindow(width, height, "Flappy Bird");	

	initParallax();
	initBird(bird);
	initObstacle(obstacle, maxObstacles);
}

void updateGame()
{
	updateParallax();
	updateBackButton(backButton);
	updateBird(bird);
	updateObstacle(obstacle, maxObstacles);

	for (int i = 0; i < maxObstacles; i++)
	{
		if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle[i].rect) ||
			checkBirdTouchGround(bird, height))
		{
			restartParallax();
			restartBird(bird);
			initObstacle(obstacle, maxObstacles);
		}
	}
}

void drawGame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawParallax();
	
	drawBird(bird);
	drawObstacle(obstacle, maxObstacles);

	drawBackButton(backButton);

	EndDrawing();
}

void deinitGame()
{
	deinitBird(bird);
	deinitParallax();
	CloseWindow();
}
}