#ifndef OVGF_GAME
#define OVGF_GAME
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