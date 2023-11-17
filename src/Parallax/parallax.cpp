#include "parallax.h"

#include "raylib.h"

namespace game
{
	static Texture2D background;
	static Texture2D midground;
	static Texture2D foreground;

	static float scrollingBackPos;
	static float scrollingMidPos;
	static float scrollingForePos;

	static float backSpeed;
	static float midSpeed;
	static float foreSpeed;

	void initParallax()
	{
		background = LoadTexture("res/parallax/Desert Parallax by Cryptogene/6 sun.png");
		midground = LoadTexture("res/parallax/Desert Parallax by Cryptogene/3 layer3.png");
		foreground = LoadTexture("res/parallax/Desert Parallax by Cryptogene/1 layer1.png");

		scrollingBackPos = 0.0f;
		scrollingMidPos = 0.0f;
		scrollingForePos = 0.0f;

		backSpeed = 60.f;
		midSpeed = 140.f;
		foreSpeed = 190.f;
	}

	void updateParallax()
	{
		scrollingBackPos -= backSpeed * GetFrameTime();
		scrollingMidPos -= midSpeed * GetFrameTime();
		scrollingForePos -= foreSpeed * GetFrameTime();

		if (scrollingBackPos <= -background.width) scrollingBackPos = 0;
		if (scrollingMidPos <= -midground.width) scrollingMidPos = 0;
		if (scrollingForePos <= -foreground.width) scrollingForePos = 0;
	}

	void drawParallax()
	{
		float scale = 1.0f;
		Color color = WHITE;
		DrawTextureEx(background, { scrollingBackPos, 0 }, 0.0f, scale, color);
		DrawTextureEx(background, { background.width + scrollingBackPos, 0 }, 0.0f, scale, color);

		DrawTextureEx(midground, { scrollingMidPos, 0 }, 0.0f, scale, color);
		DrawTextureEx(midground, { midground.width + scrollingMidPos, 0 }, 0.0f, scale, color);

		DrawTextureEx(foreground, { scrollingForePos, static_cast<float>(GetScreenHeight()) - foreground.height }, 0.0f, scale, color);
		DrawTextureEx(foreground, { foreground.width + scrollingForePos, static_cast<float>(GetScreenHeight()) - foreground.height }, 0.0f, scale, color);
	}

	void restartParallax()
	{
		scrollingBackPos = 0.0f;
		scrollingMidPos = 0.0f;
		scrollingForePos = 0.0f;
	}

	void deinitParallax()
	{
		UnloadTexture(background);
		UnloadTexture(midground);
		UnloadTexture(foreground);
	}
}