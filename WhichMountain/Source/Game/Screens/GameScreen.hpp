#pragma once
#ifndef GAME_SCREENS_GAMESCREEN_HPP
#define GAME_SCREENS_GAMESCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/Shader.hpp"
#include "../../Engine/Model.hpp"

#include <memory>

namespace game
{
	namespace screens
	{
		class GameScreen : public IScreen
		{
		public:
			static IScreenPtr Create(Window* window, InputManager* input) {
				return std::make_unique<GameScreen>(window, input);
			}

			GameScreen(Window* window, InputManager* input);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window* m_window;
			InputManager* m_input;
			ShaderPtr m_shader;
			ModelPtr m_model;
			float m_rotation;
		};
	}
}

using game::screens::GameScreen;

#endif
