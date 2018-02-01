#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_GAME_H
#define OVGF_GAME_H
#include <ovgfWindow.h>
#include <stdexcept>

class OvgfGame {
public:
	void launch();

	OvgfGame();

private:
	OvgfWindow window; //Internally relies on GLFW for window abstraction - implements basic functionality
	void mainLoop();
};
#endif