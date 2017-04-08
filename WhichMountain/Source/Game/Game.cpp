#include <Game/Game.hpp>
#include <Game/GameScreen.hpp>
#include <GL/glew.h>

namespace game
{
	Game::Game() :
		m_window("Race to Which Mountain?", 1280, 720)
	{
		m_window.VerticalSync(true);

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_screens.Switch(GameScreen::Create(&m_window, &m_input));
	}

	void Game::Update(int elapsedTime)
	{
		m_window.ProcessEvents();

		m_input.ProcessEvents(m_window.GetEvents());

		m_screens.Update(elapsedTime);
	}

	void Game::Draw(int elapsedTime)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_screens.Draw(elapsedTime);

		m_window.SwapBuffers();
	}

	void Game::Run()
	{
		static const int UPDATE_FREQ = 16;
		int timeSinceUpdate = 0;

		int prevTime = m_window.GetTicks();

		while (!m_window.ShouldClose())
		{
			int currentTime = m_window.GetTicks();
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
