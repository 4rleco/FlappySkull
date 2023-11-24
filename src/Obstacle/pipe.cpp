#include "pipe.h"

namespace game
{
	void initPipe(Pipe& pipe)
	{
		pipe.rect.x =0;
		pipe.rect.y = 0;
		pipe.rect.width = 50;
		pipe.rect.height = 50;

		pipe.color = RED;
	}
}