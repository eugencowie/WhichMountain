#pragma once
#ifndef GAME_SCREENS_HELPER_HPP
#define GAME_SCREENS_HELPER_HPP

#include "../../Engine/ScreenManager.hpp"

namespace game
{
	namespace screens
	{
		/**
		 * Create a new instance of a screen and return a unique pointer to it.
		 */
		template<typename T>
		static std::unique_ptr<T> Create(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio)
		{
			return std::make_unique<T>(window, input, screens, content, audio);
		};
	}
}

#endif
