#pragma once
#ifndef GAME_SCREENS_LOADINGSCREEN_HPP
#define GAME_SCREENS_LOADINGSCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/AudioManager.hpp"
#include "../../Engine/Sprite.hpp"

#include "Helper.hpp"
#include <vector>
#include <memory>

namespace game
{
	namespace screens
	{
		/**
		 * Shows a loading graphic while loading all of the content for the game screen.
		 */
		class LoadingScreen : public IScreen
		{
		public:
			LoadingScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window& m_window;
			InputManager& m_input;
			ScreenManager& m_screens;
			ContentManager& m_content;
			AudioManager& m_audio;

			Sprite m_sprite;
			bool m_hasDrawn;
		};
	}
}

using game::screens::LoadingScreen;

#endif
