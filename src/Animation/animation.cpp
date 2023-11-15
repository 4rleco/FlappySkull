#include "animation.h"

namespace game
{
void initAnimation(Animation& animation, float textureWidth, float textureHeight, int totalFrames)
{
	animation.maxFrames = totalFrames;
	animation.frameRect = { 0.0f, 0.0f, textureWidth / animation.maxFrames, textureHeight };
	animation.currentFrame = 0;
	animation.framesCounter = 0;
	animation.frameLenght = 0.04f;
	animation.frameCounterIncrement = 0.1f;
}

void updateAnimation(Animation& animation, float textureWidth)
{
	animation.framesCounter += animation.frameCounterIncrement * GetFrameTime();

	if (animation.framesCounter >= animation.frameLenght)
	{
		animation.framesCounter = 0;
		animation.currentFrame++;

		if (animation.currentFrame >= animation.maxFrames) animation.currentFrame = 0;

		animation.frameRect.x = static_cast<float>(animation.currentFrame) *  textureWidth / animation.maxFrames;
	}
}

Rectangle getFrameRect(Animation animation)
{
	return animation.frameRect;
}
}