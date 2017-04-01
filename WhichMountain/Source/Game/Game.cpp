#include <Game/Game.hpp>
#include <Engine/Engine.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	Game::Game()
	{
		Engine::Initialise();

		m_window = Window::Create("Race to Which Mountain?", 1280, 720);
		m_window->VerticalSync(true);

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_input = InputManager::Create(m_window);

		m_shader = Shader::Create("../../../../Content/Shaders/Textured.vert", "../../../../Content/Shaders/Textured.frag");

		m_model = Model::Create(m_shader, "../../../../Content/Models/RetroRacer/RetroRacer.obj");

		m_rotation = 0;
	}

	Game::~Game()
	{
		Engine::Finalise();
	}

	void Game::Update(int elapsedTime)
	{
		m_window->ProcessEvents();

		m_input->Update();

		if (m_input->IsJustReleased(SDLK_ESCAPE))
		{
			m_window->Close();
		}
	}

	void Game::Draw(int elapsedTime)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = glm::lookAt(glm::vec3(3, 1.5f, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		m_rotation += glm::radians(elapsedTime / 25.f);
		glm::mat4 model = glm::rotate(glm::mat4(), m_rotation, glm::vec3(0, 1, 0));

		m_model->Draw(model, view, proj);

		m_window->SwapBuffers();
	}

	void Game::Run()
	{
		static const int UPDATE_FREQ = 16;
		int timeSinceUpdate = 0;

		int prevTime = m_window->GetTicks();

		while (!m_window->ShouldClose())
		{
			int currentTime = m_window->GetTicks();
			int elapsedTime = currentTime - prevTime;

			timeSinceUpdate += elapsedTime;
			while (timeSinceUpdate >= UPDATE_FREQ)
			{
				timeSinceUpdate -= UPDATE_FREQ;
				Update(UPDATE_FREQ);
			}

			Draw(elapsedTime);

			prevTime = currentTime;
		}
	}
}
