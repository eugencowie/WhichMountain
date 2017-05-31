#include "MenuScreen.hpp"
#include "GameScreen.hpp"

namespace game
{
	namespace screens
	{
		MenuScreen::MenuScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio) :
			m_window(window),
			m_input(input),
			m_screens(screens),
			m_content(content),
			m_audio(audio),
			m_startButton(m_content, "Shaders/Textured", "Textures/Menu/Buttons/Start.png", "Textures/Menu/Buttons/StartHover.png", {640, 400}, {1280, 720}, {0.5f, 0.5f}),
			m_helpButton(m_content, "Shaders/Textured", "Textures/Menu/Buttons/Help.png", "Textures/Menu/Buttons/HelpHover.png", {640, 500}, {1280, 720}, {0.5f, 0.5f}),
			m_exitButton(m_content, "Shaders/Textured", "Textures/Menu/Buttons/Exit.png", "Textures/Menu/Buttons/ExitHover.png", {640, 600}, {1280, 720}, {0.5f, 0.5f})
		{
		}

		void MenuScreen::Update(int elapsedTime)
		{
			m_startButton.Update(m_input);
			m_helpButton.Update(m_input);
			m_exitButton.Update(m_input);

			if (m_startButton.IsClicked())
			{
				m_screens.Switch(GameScreen::Create(m_window, m_input, m_screens, m_content, m_audio));
			}

			if (m_helpButton.IsClicked())
			{
				// TODO
			}

			if (m_exitButton.IsClicked())
			{
				m_window.Close();
			}
		}

		void MenuScreen::Draw(int elapsedTime)
		{
			m_startButton.Draw();
			m_helpButton.Draw();
			m_exitButton.Draw();
		}
	}
}
