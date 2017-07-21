#include "Game.hpp"
#include "Screens/LoadingScreen.hpp"

#include <GL/glew.h>

namespace game
{
	/**
	 * Create an instance of the class.
	 */
	Game::Game() :
		m_window("Race to Which Mountain?", 1280, 720),
		m_content("Content")
	{
		// Enable VSync.
		m_window.VerticalSync(true);

		// Set up OpenGL parameters.
		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_MULTISAMPLE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Switch to the loading screen initially.
		m_screens.Switch(screens::Create<LoadingScreen>(m_window, m_input, m_screens, m_content, m_audio));
	}

	/**
	 * Called when the game should update.
	 */
	void Game::Update(int elapsedTime)
	{
		// Process SDL window events.
		m_window.ProcessEvents();

		// Process SDL input events.
		m_input.ProcessEvents(m_window.GetEvents());

		// Update the screens.
		m_screens.Update(elapsedTime);
	}

	/**
	 * Called when the game should draw.
	 */
	void Game::Draw(int elapsedTime)
	{
		// Clear the backbuffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw the screens.
		m_screens.Draw(elapsedTime);

		// Swap the backbuffer.
		m_window.SwapBuffers();
	}

	/**
	 * Run the game from start to finish. Contains the main game loop.
	 */
	void Game::Run()
	{
		// We want to call Update() every 16ms.
		static const int UPDATE_FREQ = 16;
		int timeSinceUpdate = 0;

#ifdef _DEBUG
		// We want to update the FPS every 1000ms.
		static const int FPS_FREQ = 1000;
		int timeSinceFps = 0;
		int framesSinceFps = 0;
#endif

		int prevTime = m_window.GetTicks();

		while (!m_window.ShouldClose())
		{
			// Calculate elapsed time.
			int currentTime = m_window.GetTicks();
			int elapsedTime = currentTime - prevTime;

			// Update if it has been more than 16ms.
			timeSinceUpdate += elapsedTime;
			while (timeSinceUpdate >= UPDATE_FREQ)
			{
				timeSinceUpdate -= UPDATE_FREQ;
				Update(UPDATE_FREQ);
			}

			// Call the Draw() function.
			Draw(elapsedTime);

#ifdef _DEBUG
			// Update the FPS if it has been more than 1000ms.
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
