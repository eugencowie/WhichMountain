#pragma once
#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <Engine/InputManager.hpp>
#include <Engine/Window.hpp>
#include <Engine/Shader.hpp>
#include <Engine/Model.hpp>

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
		ShaderPtr m_shader;
		ModelPtr m_model;

		float m_rotation;
	};
}

using game::Game;

#endif
