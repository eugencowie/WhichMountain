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
		for (auto it = m_screens.begin(); it != m_screens.end(); ++it)
		{
			(*it)->Update(elapsedTime);
		}
	}

	void ScreenManager::Draw(int elapsedTime)
	{
		for (auto it = m_screens.begin(); it != m_screens.end(); ++it)
		{
			(*it)->Draw(elapsedTime);
		}
	}
}
