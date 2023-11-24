#pragma once

#include "raylib.h"

namespace game
{

	struct Pipe
	{
		Rectangle rect;
		Color color;
	};

	void InitPipe(Pipe& pipe);
}