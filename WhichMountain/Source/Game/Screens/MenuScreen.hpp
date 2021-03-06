#pragma once
#ifndef GAME_SCREENS_MENUSCREEN_HPP
#define GAME_SCREENS_MENUSCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/AudioManager.hpp"
#include "../../Engine/Sprite.hpp"
#include "../../Engine/Button.hpp"

#include "Helper.hpp"
#include <memory>

namespace game
{
	namespace screens
	{
		/**
		 * The main menu screen, where players can start a level or exit the game.
		 */
		class MenuScreen : public IScreen
		{
		public:
			MenuScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window& m_window;
			InputManager& m_input;
			ScreenManager& m_screens;
			ContentManager& m_content;
			AudioManager& m_audio;

			Sprite m_background;
			Sprite m_helpScreen;

			Button m_startButton;
			Button m_helpButton;
			Button m_exitButton;

			bool m_showHelp;
		};
	}
}

using game::screens::MenuScreen;

#endif
