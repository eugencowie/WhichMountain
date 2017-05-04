#include "InputManager.hpp"

namespace engine
{
	void InputManager::ProcessEvents(std::vector<SDL_Event> events)
	{
		m_prevKeys = m_currKeys;
		m_prevButtons = m_currButtons;

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

				case SDL_MOUSEBUTTONDOWN:
					m_currButtons.push_back(e.button.button);
					break;

				case SDL_MOUSEBUTTONUP:
					m_currButtons.remove(e.button.button);
					break;

				case SDL_MOUSEMOTION:
					m_prevMousePos = m_currMousePos;
					m_currMousePos = {e.motion.x, e.motion.y};
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

	bool InputManager::IsBtnDown(Uint8 button) const
	{
		for (auto it = m_currButtons.rbegin(); it != m_currButtons.rend(); ++it)
		{
			if ((*it) == button)
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

	bool InputManager::WasBtnDown(Uint8 button) const
	{
		for (auto it = m_prevButtons.rbegin(); it != m_prevButtons.rend(); ++it)
		{
			if ((*it) == button)
			{
				return true;
			}
		}

		return false;
	}
}
