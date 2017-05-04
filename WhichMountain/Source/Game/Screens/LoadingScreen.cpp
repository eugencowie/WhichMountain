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
			m_sprite(m_content, "Shaders/Textured", "Textures/Loading.png", {1280, 720}),
			m_hasDrawn(false)
		{
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
			m_sprite.Draw({0,0});
			m_hasDrawn = true;
		}
	}
}
