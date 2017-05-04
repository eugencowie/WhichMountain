#include "MenuScreen.hpp"
#include "GameScreen.hpp"

namespace game
{
	namespace screens
	{
		MenuScreen::MenuScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content) :
			m_window(window),
			m_input(input),
			m_screens(screens),
			m_content(content)
		{
		}

		void MenuScreen::Update(int elapsedTime)
		{
			if (m_input->IsKeyJustReleased(SDLK_RETURN))
			{
				m_screens->Switch(GameScreen::Create(m_window, m_input, m_screens, m_content));
			}
		}

		void MenuScreen::Draw(int elapsedTime)
		{
		}
	}
}
