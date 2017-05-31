#include "LoadingScreen.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

namespace game
{
	namespace screens
	{
		LoadingScreen::LoadingScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio) :
			m_window(window),
			m_input(input),
			m_screens(screens),
			m_content(content),
			m_audio(audio),
			m_sprite(m_content, "Shaders/Textured", "Textures/Loading.png", {1280, 720}),
			m_hasDrawn(false)
		{
		}

		void LoadingScreen::Update(int elapsedTime)
		{
			if (m_hasDrawn)
			{
				game::screens::Create<GameScreen>(m_window, m_input, m_screens, m_content, m_audio);
				m_screens.Switch(game::screens::Create<MenuScreen>(m_window, m_input, m_screens, m_content, m_audio));
			}
		}

		void LoadingScreen::Draw(int elapsedTime)
		{
			m_sprite.Draw({0,0});
			m_hasDrawn = true;
		}
	}
}
