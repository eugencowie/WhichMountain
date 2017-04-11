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

	bool InputManager::IsDown(SDL_Keycode key)
	{
		for (auto pressedKey : m_currKeys)
		{
			if (pressedKey == key)
			{
				return true;
			}
		}

		return false;
	}

	bool InputManager::WasDown(SDL_Keycode key)
	{
		for (auto pressedKey : m_prevKeys)
		{
			if (pressedKey == key)
			{
				return true;
			}
		}

		return false;
	}
}
