#pragma once
#ifndef GAME_GAME_SCREEN_HPP
#define GAME_GAME_SCREEN_HPP

#include <Engine/ScreenManager.hpp>
#include <Engine/InputManager.hpp>
#include <Engine/Shader.hpp>
#include <Engine/Model.hpp>

namespace game
{
	class GameScreen : public IScreen
	{
	public:
		static std::shared_ptr<GameScreen> Create(WindowPtr window, InputManagerPtr input);

		GameScreen(WindowPtr window, InputManagerPtr input);

		virtual void Update(int elapsedTime) override;
		virtual void Draw(int elapsedTime) override;

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
