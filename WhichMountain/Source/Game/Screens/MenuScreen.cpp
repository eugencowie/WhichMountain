#include "MenuScreen.hpp"
#include "GameScreen.hpp"

namespace game
{
	namespace screens
	{
		/**
		 * Create an instance of the class.
		 */
		MenuScreen::MenuScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio) :
			m_window(window),
			m_input(input),
			m_screens(screens),
			m_content(content),
			m_audio(audio),
			m_background(content, "Shaders/Textured", "Textures/MenuScreen.jpg", {1280,720}),
			m_startButton(m_content, "Shaders/Textured", "Textures/Buttons/Start.png", "Textures/Buttons/StartHover.png", {440, 600}, {1280, 720}, {0.5f, 0.5f}),
			m_helpButton(m_content, "Shaders/Textured", "Textures/Buttons/Help.png", "Textures/Buttons/HelpHover.png", {640, 600}, {1280, 720}, {0.5f, 0.5f}),
			m_exitButton(m_content, "Shaders/Textured", "Textures/Buttons/Exit.png", "Textures/Buttons/ExitHover.png", {840, 600}, {1280, 720}, {0.5f, 0.5f})
		{
		}

		/**
		 * Called when the screen should update.
		 */
		void MenuScreen::Update(int elapsedTime)
		{
			m_startButton.Update(m_input);
			m_helpButton.Update(m_input);
			m_exitButton.Update(m_input);

			if (m_startButton.IsClicked())
			{
				// Switch to the game screen.
				m_screens.Switch(game::screens::Create<GameScreen>(m_window, m_input, m_screens, m_content, m_audio));
			}

			if (m_helpButton.IsClicked())
			{
				// TODO
			}

			if (m_exitButton.IsClicked())
			{
				// Exit game.
				m_window.Close();
			}
		}

		/**
		 * Called when the screen should draw.
		 */
		void MenuScreen::Draw(int elapsedTime)
		{
			m_background.Draw({0,0}, -1);

			m_startButton.Draw();
			m_helpButton.Draw();
			m_exitButton.Draw();
		}
	}
}
