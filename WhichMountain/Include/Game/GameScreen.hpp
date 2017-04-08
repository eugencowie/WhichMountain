#pragma once
#ifndef GAME_GAMESCREEN_HPP
#define GAME_GAMESCREEN_HPP

#include "../Engine/Window.hpp"
#include "../Engine/InputManager.hpp"
#include "../Engine/ScreenManager.hpp"
#include "../Engine/Shader.hpp"
#include "../Engine/Model.hpp"

#include <memory>

namespace game
{
	class GameScreen : public IScreen
	{
	public:
		static auto Create(WindowPtr window, InputManagerPtr input) {
			return std::make_shared<GameScreen>(window, input);
		}

		GameScreen(WindowPtr window, InputManagerPtr input);

		void Update(int elapsedTime) override;
		void Draw(int elapsedTime) override;

	private:
		InputManagerPtr m_input;
		WindowPtr m_window;
		ShaderPtr m_shader;
		ModelPtr m_model;
		float m_rotation;
	};
}

using game::GameScreen;

#endif
