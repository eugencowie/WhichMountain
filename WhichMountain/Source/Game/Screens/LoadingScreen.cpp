#include "LoadingScreen.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

namespace game
{
	namespace screens
	{
		/**
		 * Create an instance of the class.
		 */
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

		/**
		 * Called when the screen should update.
		 */
		void LoadingScreen::Update(int elapsedTime)
		{
			// If the loading sprite has been drawn at least once...
			if (m_hasDrawn)
			{
				// Create an instance of the game screen to load the required content.
				game::screens::Create<GameScreen>(m_window, m_input, m_screens, m_content, m_audio);

				// Switch to the main menu when done.
				m_screens.Switch(game::screens::Create<MenuScreen>(m_window, m_input, m_screens, m_content, m_audio));
			}
		}

		/**
		 * Called when the screen should draw.
		 */
		void LoadingScreen::Draw(int elapsedTime)
		{
			// Draw the sprite texture.
			m_sprite.Draw({0,0});

			// Indicate that the loading texture has been drawn.
			m_hasDrawn = true;
		}
	}
}
