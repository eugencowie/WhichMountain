#include "ScreenManager.hpp"

namespace engine
{
	void ScreenManager::Switch(IScreenPtr screen)
	{
		Clear();
		Push(std::move(screen));
	}

	void ScreenManager::Push(IScreenPtr screen)
	{
		m_screens.push_back(std::move(screen));
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
		for (int i = 0; i < m_screens.size(); ++i)
		{
			m_screens[i]->Update(elapsedTime);
		}
	}

	void ScreenManager::Draw(int elapsedTime)
	{
		for (int i = 0; i < m_screens.size(); ++i)
		{
			m_screens[i]->Draw(elapsedTime);
		}
	}
}
