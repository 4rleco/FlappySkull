#include "game.h"

#include "Menu/menu.h"
#include "Menu/credits.h"

#include "Parallax/parallax.h"

#include "Bird/bird.h"

#include "Obstacle/pipe.h"         
#include "Obstacle/obstacle.h"

#include "raylib.h"

namespace game
{
	extern CurrentScreen currentScreen;
	const int maxObstacles = 4;
	static Bird bird1;
	static Pipe pipeUp;
	static Pipe pipeDown;
	float bird1PosX = 120.0f;
	float bird1PosY = 240.0f;
	static Bird bird2;
	float bird2PosX = 40.0f;
	float bird2PosY = 240.0f;
	static Obstacle obstacle;
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
				restartBird(bird1, bird1PosX, bird1PosY);
				restartBird(bird2, bird2PosX, bird2PosY);
				
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
		SetRandomSeed(static_cast<unsigned int>(time(NULL)));

		InitWindow(width, height, "Flappy Bird");

		initParallax();
		initBird(bird1, KeyboardKey::KEY_W, 120.0f, 240.0f);
		initBird(bird2, KeyboardKey::KEY_UP, 40.0f, 240.0f);
		initObstacle(bird1, obstacle);
	}

	void singlePlayer()
	{
		if (!bird1.died)
		{
			updateParallax();
			updateBackButton(backButton);
			updateBird(bird1);
			updateObstacle(obstacle);

			/*for (int i = 0; i < maxObstacles; i++)
			{
				if (bird1.pos.x > obstacle[i].rect.x + obstacle[i].rect.width)
				{
					bird1.gainScore = true;
				}

				if (bird1.gainScore)
				{
					if (i % 2 == 0)
					{
						bird1.score += obstacle[i].givePoints;

						obstacle[i].givePoints = 0;
					}

					bird1.gainScore = false;
				}

				if (CheckCollisionCircleRec(bird1.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird1, height))
				{
					bird1.died = true;
				}
			}*/
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
			updateObstacle(obstacle);

			/*for (int i = 0; i < maxObstacles; i++)
			{
				if (bird1.pos.x > obstacle[i].rect.x && bird2.pos.x > obstacle[i].rect.x)
				{
					bird1.gainScore = true;
					bird2.gainScore = true;
				}

				if (bird1.gainScore && bird2.gainScore)
				{
					if (i % 2 == 0)
					{
						bird1.score += obstacle[i].givePoints;

						obstacle[i].givePoints = 0;
					}

					bird1.gainScore = false;
				}

				if (CheckCollisionCircleRec(bird1.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird1, height) ||
					CheckCollisionCircleRec(bird2.center, bird1.radius, obstacle[i].rect) ||
					checkBirdTouchGround(bird2, height))
				{
					bird1.died = true;
					bird2.died = true;
				}
			}*/
		}
	}

	void drawSinglePlayerGame()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		drawParallax();

		drawBird(bird1);
		drawObstacle(obstacle);

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
				restartBird(bird1, bird1PosX, bird1PosY);
				initObstacle(bird1, obstacle);
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
		drawObstacle(obstacle);

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
				restartBird(bird1, bird1PosX, bird1PosY);
				restartBird(bird2, bird2PosX, bird2PosY);
				initObstacle(bird1, obstacle);
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