#pragma once
#ifndef ENGINE_INPUTMANAGER_HPP
#define ENGINE_INPUTMANAGER_HPP

#include <SDL.h>
#include <vector>
#include <list>

namespace engine
{
	class InputManager
	{
	public:
		void ProcessEvents(std::vector<SDL_Event> events);

		bool IsDown(SDL_Keycode key);
		bool WasDown(SDL_Keycode key);
		bool IsJustPressed(SDL_Keycode key) { return IsDown(key) && !WasDown(key); }
		bool IsJustReleased(SDL_Keycode key) { return !IsDown(key) && WasDown(key); }

	private:
		std::list<SDL_Keycode> m_currKeys;
		std::list<SDL_Keycode> m_prevKeys;
	};
}

using engine::InputManager;

#endif
