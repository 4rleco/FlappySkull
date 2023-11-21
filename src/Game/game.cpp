#include "game.h"

#include "Menu/menu.h"
#include "Menu/credits.h"

#include "Parallax/parallax.h"

#include "Bird/bird.h"

#include "Obstacle/obstacle.h"

#include "raylib.h"

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
			SetExitKey(NULL);

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
		if (!bird.died)
		{
			updateParallax();
			updateBackButton(backButton);
			updateBird(bird);
			updateObstacle(obstacle, maxObstacles);

			for (int i = 0; i < maxObstacles; i++)
			{
				if (bird.pos.x > obstacle[i].rect.x)
				{
					bird.score += 10;
				}

				if (CheckCollisionCircleRec(bird.center, bird.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird, height))
				{
					bird.died = true;
				}
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

		if (!bird.died)
		{
			DrawText(TextFormat("%i", bird.score), 10, 5, 30, BLACK);
		}

		if (bird.died)
		{
			DrawText("Game Over", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 - 80, 60, BLACK);
			DrawText("Score:", GetScreenWidth() / 2 - 30, GetScreenHeight() / 2, 30, BLACK);
			DrawText(TextFormat("%i", bird.score), GetScreenWidth() / 2 + 80, GetScreenHeight() / 2, 30, BLACK);
			DrawText("Press \"Enter\" to restart game", GetScreenWidth() / 2 - 180, GetScreenHeight() / 2 + 60, 30, BLACK);

			if (IsKeyPressed(KEY_ENTER))
			{
				restartParallax();
				restartBird(bird);
				initObstacle(obstacle, maxObstacles);
			}
		}

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