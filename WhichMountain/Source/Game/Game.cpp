#include "Game.hpp"
#include "Screens/LoadingScreen.hpp"

#include <GL/glew.h>

namespace game
{
	Game::Game() :
		m_window("Race to Which Mountain?", 1280, 720),
		m_content("Content", "../../../../Content")
	{
		m_window.VerticalSync(true);

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_MULTISAMPLE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_screens.Switch(game::screens::Create<LoadingScreen>(m_window, m_input, m_screens, m_content, m_audio));
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

#ifdef _DEBUG
		static const int FPS_FREQ = 1000;
		int timeSinceFps = 0;
		int framesSinceFps = 0;
#endif

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

#ifdef _DEBUG
			timeSinceFps += elapsedTime;
			if (timeSinceFps >= FPS_FREQ)
			{
				timeSinceFps -= FPS_FREQ;
				std::string title = "Race to Which Mountain? (FPS: " + std::to_string(framesSinceFps) + ")";
				m_window.SetTitle(title.c_str());
				framesSinceFps = 0;
			}
			framesSinceFps++;
#endif

			prevTime = currentTime;
		}
	}
}
