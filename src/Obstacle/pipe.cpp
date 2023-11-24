#include "pipe.h"

namespace game
{
	void initPipe(Pipe& pipe)
	{
		pipe.rect.x = static_cast<float>(GetScreenWidth());
		pipe.rect.y = 0;
		pipe.rect.width = 50;
		pipe.rect.height = static_cast<float>(GetScreenHeight());

		pipe.color = RED;
	}
}