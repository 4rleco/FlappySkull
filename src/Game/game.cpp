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
static Bird bird;
static Obstacle obstacle;
static Obstacle topObstacle;
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
	initObstacle(obstacle, false);
	initObstacle(topObstacle, true);
}

void updateGame()
{
	updateParallax();
	updateBackButton(backButton);
	updateBird(bird);
	updateObstacle(obstacle, false);
	updateObstacle(topObstacle, true);

	if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle.rect) ||
		checkBirdTouchGround(bird, height))
	{
		restartParallax();
		restartBird(bird);
		restartObstacle(obstacle, false);
		restartObstacle(topObstacle, true);
	}
}

void drawGame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawParallax();
	drawBackButton(backButton);
	
	drawBird(bird);
	drawObstacle(obstacle);
	drawObstacle(topObstacle);

	EndDrawing();
}

void deinitGame()
{
	deinitBird(bird);
	deinitParallax();
	CloseWindow();
}
}