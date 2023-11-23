#pragma once

#include "raylib.h"

namespace game
{
	struct Bird
	{
		Texture2D texture;
		Vector2 pos;
		Vector2 center;
		float jumpForce;
		float radius;
		float gravity;
		float velocity;
		bool flying;
		int score;
		int keyUp;
		bool died;
		bool gainScore;
		Color color;
	};

	void initBird(Bird& bird, int keyUp, float posX, float posY);
	void updateBird(Bird& bird);
	void drawBird(Bird bird);
	void restartBird(Bird& bird, float posX, float posY);
	bool checkBirdTouchGround(Bird& bird, int screenHeight);
	int getBirdDiameter();
	void deinitBird(Bird& bird);
}