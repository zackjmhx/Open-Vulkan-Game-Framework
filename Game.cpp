/**OVGF is meant, for now, to be a Vulkan based rapid prototyping tool to assist in game development.
***Once the framework is sufficient as such a tool, then development will shift focus to being suitable for release products*/
#include "Game.h"

class OvgfGame {

public:

	void launch() {

		if (window.getOvgfWindow(600, 400) == nullptr)
			throw std::runtime_error("Failed to create OVGF window.");
	}

private:
	OvgfWindow window; //Internally relies on GLFW for window abstraction - implements basic functionality


};