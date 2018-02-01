#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_GAME_H
#define OVGF_GAME_H
#include <ovgfWindow.h>

namespace ovgf {

	class Game {
	public:
		void launch();

		Game();

	private:
		Window window; //Internally relies on GLFW for window abstraction - implements basic functionality
		void mainLoop();
	};
}
#endif