#if _pragma_once_support
#pragma once
#endif

#ifndef OVGF_GAME_HPP
#define OVGF_GAME_HPP
#include <string>
#include <spimpl.h>

namespace ovgf {

	class Game {
	public:
		Game(std::string name, int wWidth, int wHeight);

		void launch();

	private:
		struct GameImpl;
		spimpl::unique_impl_ptr<GameImpl> pGameImpl;
	};
}
#endif