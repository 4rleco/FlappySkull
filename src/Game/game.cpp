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
static Button playButton;
static Button creditsButton;
static Button exitButton;
Button backButton;

static const int width = 1024;
static const int height = 768;
static const int fontSize = 30;
static Color fontColor = RED;

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
	initObstacle(obstacle);
}

void updateGame()
{
	updateParallax();
	updateBackButton(backButton);
	updateBird(bird);
	updateObstacle(obstacle, width, height);

	if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle.rect) ||
		checkBirdTouchGround(bird, height))
	{
		restartParallax();
		restartBird(bird);
		restartObstacle(obstacle, width, height);
	}
}

void drawGame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	drawParallax();
	drawBackButton(backButton);
	DrawText("v 0.1 ", width - MeasureText("v 0.1 ", fontSize),
		height - static_cast<int>(MeasureTextEx(GetFontDefault(), "v 0.1 ", fontSize, 0).y), fontSize, fontColor);
	drawBird(bird);
	drawObstacle(obstacle);

	EndDrawing();
}

void deinitGame()
{
	deinitBird(bird);
	deinitParallax();
	CloseWindow();
}
}