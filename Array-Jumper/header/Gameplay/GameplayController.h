#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:

		

	public:
		void intialize();
		void update();
		void render();
		void processObstacle();
		bool isObstacle(Level::BlockType value);
		void onPositionChanged(int position);
	};
}
