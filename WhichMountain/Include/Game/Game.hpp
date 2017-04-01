#pragma once
#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <Engine/InputManager.hpp>
#include <Engine/Window.hpp>
#include <Engine/Shader.hpp>
#include <Engine/Texture.hpp>
#include <Engine/Mesh.hpp>

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
		TexturePtr m_texture;
		MeshPtr m_mesh;
	};
}

using game::Game;

#endif
