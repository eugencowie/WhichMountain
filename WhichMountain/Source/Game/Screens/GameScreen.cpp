#include "GameScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	GameScreen::GameScreen(Window* window, InputManager* input, ContentManager* content) :
		m_window(window),
		m_input(input),
		m_player(content)
	{
	}

	void GameScreen::Update(int elapsedTime)
	{
		if (m_input->IsJustReleased(SDLK_ESCAPE))
		{
			m_window->Close();
		}
	}

	void GameScreen::Draw(int elapsedTime)
	{
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = glm::lookAt(glm::vec3(3, 1.5f, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		m_player.Draw(elapsedTime, view, proj);
	}
}
