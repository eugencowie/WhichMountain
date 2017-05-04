#include "GameScreen.hpp"
#include "MenuScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	GameScreen::GameScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content) :
		m_window(window),
		m_input(input),
		m_screens(screens),
		m_content(content),
		m_ground(content),
		m_player(content, input)
	{
		m_obstacles.push_back(Obstacle(content, {-5,0,-12}, {1,1,1}));
		m_obstacles.push_back(Obstacle(content, { 5,0,-20}, {1,1,1}));
	}

	void GameScreen::Update(int elapsedTime)
	{
		m_player.Update(elapsedTime);

		if (m_input->IsKeyJustReleased(SDLK_ESCAPE))
		{
			m_screens->Switch(MenuScreen::Create(m_window, m_input, m_screens, m_content));
		}
	}

	void GameScreen::Draw(int elapsedTime)
	{
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = glm::lookAt(m_player.GetPosition() + glm::vec3{0,1,5}, m_player.GetPosition(), glm::vec3(0, 1, 0));

		for (int i = 0; i < m_obstacles.size(); i++)
		{
			m_obstacles[i].Draw(view, proj);
		}

		m_ground.Draw(view, proj);
		m_player.Draw(view, proj);
	}
}
