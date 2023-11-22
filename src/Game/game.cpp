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
	static Bird bird1;
	static Bird bird2;
	static Obstacle obstacle[maxObstacles];
	static Button onePlayerButton;
	static Button twoPlayerButton;
	static Button creditsButton;
	static Button exitButton;
	Button backButton;

	const int width = 1024;
	const int height = 768;

	void initGame();
	void singlePlayer();
	void multiPlayer();
	void drawSinglePlayerGame();
	void drawMultiPlayerame();
	void deinitGame();

	void gameLoop()
	{
		initGame();

		initButtons(onePlayerButton, twoPlayerButton, creditsButton, exitButton, backButton);

		while (!WindowShouldClose())
		{
			SetExitKey(NULL);

			switch (currentScreen)
			{
			case MENU:
				updateMenu(onePlayerButton, twoPlayerButton, creditsButton, exitButton);
				drawButtons(onePlayerButton, twoPlayerButton, creditsButton, exitButton);
				break;
			case SINGLEPLAYER:
				singlePlayer();
				drawSinglePlayerGame();
				break;
			case MULTIPLAYER:
				multiPlayer();
				drawMultiPlayerame();
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
		initBird(bird1, KeyboardKey::KEY_W, 120.0f, 240.0f);
		initBird(bird2, KeyboardKey::KEY_UP, 90.0f, 240.0f);
		initObstacle(obstacle, maxObstacles);
	}

	void singlePlayer()
	{
		if (!bird1.died || !bird2.died)
		{
			updateParallax();
			updateBackButton(backButton);
			updateBird(bird1);
			updateObstacle(obstacle, maxObstacles);

			for (int i = 0; i < maxObstacles; i++)
			{
				if (bird1.pos.x > obstacle[i].rect.x)
				{
					bird1.score += 10;
				}

				if (CheckCollisionCircleRec(bird1.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird1, height))
				{
					bird1.died = true;
				}
			}
		}
	}

	void multiPlayer()
	{
		if (!bird1.died || !bird2.died)
		{
			updateParallax();
			updateBackButton(backButton);
			updateBird(bird1);
			updateBird(bird2);
			updateObstacle(obstacle, maxObstacles);

			for (int i = 0; i < maxObstacles; i++)
			{
				if (bird1.pos.x > obstacle[i].rect.x || bird2.pos.x > obstacle[i].rect.x)
				{
					bird1.score += 10;
				}

				if (CheckCollisionCircleRec(bird1.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird1, height) ||
					CheckCollisionCircleRec(bird2.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird2, height))
				{
					bird1.died = true;
					bird2.died = true;
				}
			}
		}
	}

	void drawSinglePlayerGame()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		drawParallax();

		drawBird(bird1);
		drawObstacle(obstacle, maxObstacles);

		if (!bird1.died)
		{
			DrawText(TextFormat("%i", bird1.score), 10, 5, 30, BLACK);
		}

		if (bird1.died)
		{
			DrawText("Game Over", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 - 80, 60, BLACK);
			DrawText("Score:", GetScreenWidth() / 2 - 30, GetScreenHeight() / 2, 30, BLACK);
			DrawText(TextFormat("%i", bird1.score), GetScreenWidth() / 2 + 80, GetScreenHeight() / 2, 30, BLACK);
			DrawText("Press \"Enter\" to restart game", GetScreenWidth() / 2 - 180, GetScreenHeight() / 2 + 60, 30, BLACK);

			if (IsKeyPressed(KEY_ENTER))
			{
				restartParallax();
				restartBird(bird1);
				initObstacle(obstacle, maxObstacles);
			}
		}

		drawBackButton(backButton);

		EndDrawing();

	}

	void drawMultiPlayerame()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		drawParallax();

		drawBird(bird1);
		drawBird(bird2);
		drawObstacle(obstacle, maxObstacles);

		if (!bird1.died || !bird2.died)
		{
			DrawText(TextFormat("%i", bird1.score), 10, 5, 30, BLACK);
		}

		if (bird1.died || bird2.died)
		{
			DrawText("Game Over", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 - 80, 60, BLACK);
			DrawText("Score:", GetScreenWidth() / 2 - 30, GetScreenHeight() / 2, 30, BLACK);
			DrawText(TextFormat("%i", bird1.score), GetScreenWidth() / 2 + 80, GetScreenHeight() / 2, 30, BLACK);
			DrawText("Press \"Enter\" to restart game", GetScreenWidth() / 2 - 180, GetScreenHeight() / 2 + 60, 30, BLACK);

			if (IsKeyPressed(KEY_ENTER))
			{
				restartParallax();
				restartBird(bird1);
				restartBird(bird2);
				initObstacle(obstacle, maxObstacles);
			}
		}

		drawBackButton(backButton);

		EndDrawing();
	}

	void deinitGame()
	{
		deinitBird(bird1);
		deinitBird(bird2);
		deinitParallax();
		CloseWindow();
	}
}