#include "GameScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	GameScreen::GameScreen(Window* window, InputManager* input, ContentManager* content) :
		m_window(window),
		m_input(input),
		m_player(content)
	{
		m_obstacles.push_back(Obstacle(content, {-5,0,8}, {1,1,1}));
		m_obstacles.push_back(Obstacle(content, { 5,0,12}, {1,1,1}));
	}

	void GameScreen::Update(int elapsedTime)
	{
		if (m_input->IsJustReleased(SDLK_ESCAPE))
		{
			m_window->Close();
		}

		m_player.Update(elapsedTime);
	}

	void GameScreen::Draw(int elapsedTime)
	{
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = glm::lookAt(glm::vec3(3, 1.5f, 3), m_player.GetPosition(), glm::vec3(0, 1, 0));

		for (int i = 0; i < m_obstacles.size(); i++)
		{
			m_obstacles[i].Draw(view, proj);
		}

		m_player.Draw(view, proj);
	}
}
