#pragma once
#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <Engine/InputManager.hpp>
#include <Engine/Window.hpp>

namespace game
{
	class Game
	{
	public:
		Game();
		~Game();

		void Run();

	private:
		void Update(int elapsedTime);
		void Draw(int elapsedTime);

		InputManagerPtr m_input;

		WindowPtr m_window;
	};
}

using game::Game;

#endif
