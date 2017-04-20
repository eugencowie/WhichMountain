#include "LoadingScreen.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

namespace game
{
	namespace screens
	{
		LoadingScreen::LoadingScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content) :
			m_window(window),
			m_input(input),
			m_screens(screens),
			m_content(content),
			m_shader(content->GetShader("Shaders/Textured")),
			m_texture(content->GetTexture("Textures/Loading.png", TextureType::DIFFUSE)),
			m_hasDrawn(false)
		{
			std::vector<Vertex> vertices = {
				{ {-1, 1,0}, {}, {0,0} }, // top left
				{ { 1, 1,0}, {}, {1,0} }, // top right
				{ { 1,-1,0}, {}, {1,1} }, // bottom right
				{ {-1,-1,0}, {}, {0,1} }  // bottom left 
			};

			std::vector<GLuint> indices = {
				3, 2, 1,
				1, 0, 3
			};

			m_mesh = Mesh::Create(m_shader, vertices, indices, {m_texture});
		}

		void LoadingScreen::Update(int elapsedTime)
		{
			if (m_hasDrawn)
			{
				GameScreen::Create(m_window, m_input, m_screens, m_content);
				m_screens->Switch(MenuScreen::Create(m_window, m_input, m_screens, m_content));
			}
		}

		void LoadingScreen::Draw(int elapsedTime)
		{
			m_mesh->Draw();
			m_hasDrawn = true;
		}
	}
}
