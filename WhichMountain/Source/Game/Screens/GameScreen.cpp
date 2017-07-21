#include "GameScreen.hpp"
#include "MenuScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <fstream>

namespace game
{
	/**
	 * Create an instance of the class.
	 */
	GameScreen::GameScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio) :
		m_window(window),
		m_input(input),
		m_screens(screens),
		m_content(content),
		m_audio(audio),
		m_camera({0,1.5f,5}),
		m_ground(content, 40),
		m_player(content, input, audio),
		m_gameOver(content, "Shaders/Textured", "Textures/GameOver.png", {1280,720}),
		m_musicPlaying(false),
		m_isGameOver(false),
		m_highscore(0),
		m_score(0)
	{
		// Create the random number generator.
		m_random.seed(std::random_device()());

		// Load high score.
		std::string line;
		std::ifstream file("Highscore.txt");
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				m_highscore = std::atoi(line.c_str());
			}
			file.close();
		}
	}

	/**
	 * Called when an instance of the class is destroyed.
	 */
	GameScreen::~GameScreen()
	{
		// Stop any playing audio.
		m_audio.StopAll();

		// Save high score.
		if (m_score > m_highscore)
		{
			std::ofstream file;
			file.open("Highscore.txt");
			if (file.is_open())
			{
				file << m_score;
				file.close();
			}
		}
	}

	/**
	 * Called when the screen should update.
	 */
	void GameScreen::Update(int elapsedTime)
	{
		if (m_input.IsKeyJustReleased(SDLK_ESCAPE))
		{
			// Switch back to the menu.
			m_screens.Switch(screens::Create<MenuScreen>(m_window, m_input, m_screens, m_content, m_audio));
			return;
		}

		if (m_isGameOver)
		{
			if (m_input.IsKeyJustReleased(SDLK_RETURN))
			{
				// Really lazy way of restarting the game.
				if (m_score > m_highscore)
				{
					std::ofstream file;
					file.open("highscore.txt");
					if (file.is_open())
					{
						file << m_score;
						file.close();
					}
				}
				m_screens.Switch(screens::Create<GameScreen>(m_window, m_input, m_screens, m_content, m_audio));
				return;
			}
		}
		else
		{
			m_score += elapsedTime;

			if (!m_musicPlaying)
			{
				// Start playing music.
				m_bgMusic = m_audio.PlaySound("Content/Audio/Killers.ogg", true);
				m_musicPlaying = true;
			}

			// Update player, camera, ground.
			m_player.Update(elapsedTime);
			m_camera.Update(m_player.GetPosition());

			m_ground.Update(m_player.GetPosition());

			// Spawn a new obstacle.
			SpawnObstacle();

			// Obstacles
			for (size_t i = m_obstacles.size(); i > 0; --i)
			{
				// Check if player has collided with obstacle.
				if (m_player.GetBounds().Intersects(m_obstacles[i-1]->GetBounds()))
				{
					m_isGameOver = true;
				}

				// Remove obstacles which the player has passed.
				if (m_obstacles[i-1]->GetBounds().GetPosition().z > m_player.GetPosition().z + 10)
				{
					m_obstacles[i-1] = m_obstacles[m_obstacles.size() - 1];
					m_obstacles.pop_back();
				}
			}
		}
	}

	/**
	 * Called when the screen should draw.
	 */
	void GameScreen::Draw(int elapsedTime)
	{
		// Create projection matrix (field of view, aspect ratio, near/far planes).
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);

		// Get the view matrix (camera).
		glm::mat4 view = m_camera.GetMatrix();

		// Draw all of the obstacles.
		for (auto it = m_obstacles.begin(); it != m_obstacles.end(); ++it)
		{
			(*it)->Draw(view, proj);
		}

		// Draw the ground.
		m_ground.Draw(view, proj);

		if (!m_isGameOver)
		{
			// Draw player if game is not over.
			m_player.Draw(view, proj);
		}
		else
		{
			// Draw game over screen.
			m_gameOver.Draw({0,0});
		}
	}

	/**
	 * Spawn a new obstacle in a random position ahead of the player.
	 */
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
