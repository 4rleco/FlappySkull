#pragma once

#include "raylib.h"

namespace game
{
struct Animation
{
	Rectangle frameRect;
	int currentFrame;
	float framesCounter;
	int maxFrames;
	float frameLenght;
	float frameCounterIncrement;
};

void initAnimation(Animation& animation, float textureWidth, float textureHeight, int totalFrames);
void updateAnimation(Animation& animation, float textureWidth);
Rectangle getFrameRect(Animation animation);
}