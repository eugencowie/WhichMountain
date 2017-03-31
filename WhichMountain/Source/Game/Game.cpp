#include <Game/Game.hpp>
#include <Engine/Engine.hpp>
#include <GL/glew.h>

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
