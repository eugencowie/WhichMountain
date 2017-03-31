#include <Game/Game.hpp>
#include <Engine/Engine.hpp>

namespace game
{
	Game::Game()
	{
		Engine::Initialise();

		m_window = Window::Create("Race to Which Mountain?", 1280, 720);
	}

	Game::~Game()
	{
		Engine::Finalise();
	}

	void Game::Update(int elapsedTime)
	{
		m_window->ProcessEvents();
	}

	void Game::Draw(int elapsedTime)
	{
	}

	void Game::Run()
	{
		int prevTime = m_window->GetTicks();

		while (!m_window->ShouldClose())
		{
			int currentTime = m_window->GetTicks();
			int elapsedTime = currentTime - prevTime;

			Update(elapsedTime);
			Draw(elapsedTime);

			prevTime = currentTime;
		}
	}
}
