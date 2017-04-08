#include <Engine/ScreenManager.hpp>

namespace engine
{
	void ScreenManager::Switch(IScreenPtr screen)
	{
		Clear();
		Push(screen);
	}

	void ScreenManager::Push(IScreenPtr screen)
	{
		m_screens.push_back(screen);
	}

	void ScreenManager::Pop()
	{
		m_screens.pop_back();
	}

	void ScreenManager::Clear()
	{
		m_screens.clear();
	}

	void ScreenManager::Update(int elapsedTime)
	{
		for (auto screen : m_screens)
		{
			screen->Update(elapsedTime);
		}
	}

	void ScreenManager::Draw(int elapsedTime)
	{
		for (auto screen : m_screens)
		{
			screen->Draw(elapsedTime);
		}
	}
}
