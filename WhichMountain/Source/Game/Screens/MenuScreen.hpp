#pragma once
#ifndef GAME_SCREENS_MENUSCREEN_HPP
#define GAME_SCREENS_MENUSCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Button.hpp"

#include <memory>

namespace game
{
	namespace screens
	{
		class MenuScreen : public IScreen
		{
		public:
			static IScreenPtr Create(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content) {
				return std::make_unique<MenuScreen>(window, input, screens, content);
			}

			MenuScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window* m_window;
			InputManager* m_input;
			ScreenManager* m_screens;
			ContentManager* m_content;

			Button m_startButton;
			Button m_helpButton;
			Button m_exitButton;
		};
	}
}

using game::screens::MenuScreen;

#endif
