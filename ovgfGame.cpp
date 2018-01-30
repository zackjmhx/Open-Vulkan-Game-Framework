/**OVGF is meant, for now, to be a Vulkan based rapid prototyping tool to assist in game development.
***Once the framework is sufficient as such a tool, then development will shift focus to being suitable for release products*/
#include "ovfgGame.h"
#include <chrono>
#include <iostream>

void OvgfGame::launch() {

	if (window.getOvgfWindow(600, 400) == nullptr)
		throw std::runtime_error("Failed to create OVGF window.");

	mainLoop();
}



void OvgfGame::mainLoop() {

	auto times = std::chrono::high_resolution_clock::now();
	uint32_t frames = 0;

	while (!glfwWindowShouldClose(window.getOvgfWindow())) {

		glfwPollEvents();

		frames++;

		if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - times).count() >= 1) {
			std::cout << "Current FPS: " << frames << std::endl;
			frames = 0;
			times = std::chrono::high_resolution_clock::now();
		}
	}

}
