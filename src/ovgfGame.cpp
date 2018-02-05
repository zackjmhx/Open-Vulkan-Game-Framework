/**OVGF is meant, for now, to be a Vulkan based rapid prototyping tool to assist in game development.
***Once the framework is sufficient as such a tool, then development will shift focus to being suitable for release products*/

//This class is currently a little redundant to Instance. TODO: Add user function definition capability
#include "ovfgGame.hpp"
#include "objects\ovgfObjectsInstance.hpp"

namespace ovgf {

	struct Game::GameImpl {
	public:
		GameImpl(std::string name, int wWidth, int wHeight);
		void launch();

	private:
		objects::Instance instance; //Internally relies on GLFW for window abstraction - implements basic functionality
	};

	Game::Game(std::string name, int wWidth, int wHeight) : pGameImpl(spimpl::make_unique_impl<GameImpl>(name, wWidth, wHeight)) {
	}

	Game::GameImpl::GameImpl(std::string name, int wWidth, int wHeight) : instance(name, wWidth, wHeight) {
	}


	void Game::launch() {
		pGameImpl->launch();
	}

	void Game::GameImpl::launch() {
		instance.launch();
	}

}