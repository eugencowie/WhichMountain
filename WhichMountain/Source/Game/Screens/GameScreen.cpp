#include "GameScreen.hpp"
#include "MenuScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	GameScreen::GameScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content, AudioManager* audio) :
		m_window(window),
		m_input(input),
		m_screens(screens),
		m_content(content),
		m_audio(audio),
		m_camera({0,1.5f,5}),
		m_ground(content),
		m_player(content, input)
	{
		m_random.seed(std::random_device()());
	}

	void GameScreen::Update(int elapsedTime)
	{
		m_player.Update(elapsedTime);
		m_camera.Update(m_player.GetPosition());

		m_ground.Update(m_player.GetPosition());

		SpawnObstacle();

		// If the list is empty, it is important to cast size_t to int because size_t(0) - 1 wraps
		// around to INT_MAX and INT_MAX >= 0 so the for loop is executed with an invalid index.
		for (int i = static_cast<int>(m_obstacles.size()) - 1; i >= 0; --i)
		{
			if (m_obstacles[i]->GetBounds().GetPosition().z > m_player.GetPosition().z + 10 || m_player.GetBounds().Intersects(m_obstacles[i]->GetBounds()))
			{
				m_obstacles[i] = m_obstacles[m_obstacles.size() - 1];
				m_obstacles.pop_back();
			}
		}

		if (m_input->IsKeyJustReleased(SDLK_ESCAPE))
		{
			m_screens->Switch(MenuScreen::Create(m_window, m_input, m_screens, m_content, m_audio));
		}
	}

	void GameScreen::Draw(int elapsedTime)
	{
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = m_camera.GetMatrix();

		for (auto it = m_obstacles.begin(); it != m_obstacles.end(); ++it)
		{
			(*it)->Draw(view, proj);
		}

		m_ground.Draw(view, proj);
		m_player.Draw(view, proj);
	}

	void GameScreen::SpawnObstacle()
	{
		static std::uniform_int_distribution<std::mt19937::result_type> dist(0, 500);

		int x = dist(m_random) - 250; // range of -250 to 250
		int y = 0;
		int z = 100;

		glm::vec3 playerPos = m_player.GetPosition();
		glm::vec3 spawnPos(playerPos.x + x, y, playerPos.z - z);

		m_obstacles.push_back(std::make_shared<Obstacle>(m_content, spawnPos));
	}
}
