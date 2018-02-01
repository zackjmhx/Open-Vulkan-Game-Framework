/**OVGF is meant, for now, to be a Vulkan based rapid prototyping tool to assist in game development.
***Once the framework is sufficient as such a tool, then development will shift focus to being suitable for release products*/
#include "ovfgGame.h"
#include <iostream>
#include <chrono>
#include <GLFW\glfw3.h>

namespace sc = ::std::chrono;
using sc::seconds;

namespace ovgf {

	Game::Game() : window() {
	}


	void Game::launch() {

		if (window.getWindow(600, 400) == nullptr)
			throw ::std::runtime_error("Failed to create OVGF window.");

		mainLoop();
	}



	void Game::mainLoop() {

		auto times = sc::high_resolution_clock::now();
		uint32_t frames = 0;

		while (!glfwWindowShouldClose(window.getWindow())) {

			glfwPollEvents();

			frames++;

			if ((sc::high_resolution_clock::now() - times) >= seconds{ 1 }) {
				::std::cout << "Current FPS: " << frames << ::std::endl;
				frames = 0;
				times = ::std::chrono::high_resolution_clock::now();
			}
		}

	}
}