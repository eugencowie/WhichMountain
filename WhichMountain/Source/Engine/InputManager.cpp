#include "InputManager.hpp"

namespace engine
{
	void InputManager::ProcessEvents(std::vector<SDL_Event> events)
	{
		m_prevKeys = m_currKeys;

		for (auto e : events)
		{
			switch (e.type)
			{
				case SDL_KEYDOWN:
					m_currKeys.push_back(e.key.keysym.sym);
					break;

				case SDL_KEYUP:
					m_currKeys.remove(e.key.keysym.sym);
					break;
			}
		}
	}

	bool InputManager::IsKeyDown(SDL_Keycode key) const
	{
		for (auto it = m_currKeys.rbegin(); it != m_currKeys.rend(); ++it)
		{
			if ((*it) == key)
			{
				return true;
			}
		}

		return false;
	}

	bool InputManager::WasKeyDown(SDL_Keycode key) const
	{
		for (auto it = m_prevKeys.rbegin(); it != m_prevKeys.rend(); ++it)
		{
			if ((*it) == key)
			{
				return true;
			}
		}

		return false;
	}
}
