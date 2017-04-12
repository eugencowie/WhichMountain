#pragma once
#ifndef GAME_SCREENS_GAMESCREEN_HPP
#define GAME_SCREENS_GAMESCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../Objects/Player.hpp"

#include <memory>

namespace game
{
	namespace screens
	{
		class GameScreen : public IScreen
		{
		public:
			static IScreenPtr Create(Window* window, InputManager* input, ContentManager* content) {
				return std::make_unique<GameScreen>(window, input, content);
			}

			GameScreen(Window* window, InputManager* input, ContentManager* content);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window* m_window;
			InputManager* m_input;
			Player m_player;
		};
	}
}

using game::screens::GameScreen;

#endif
