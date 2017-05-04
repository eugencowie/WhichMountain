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

		bool IsKeyDown(SDL_Keycode key) const;
		bool WasKeyDown(SDL_Keycode key) const;
		bool IsKeyJustPressed(SDL_Keycode key) const { return IsKeyDown(key) && !WasKeyDown(key); }
		bool IsKeyJustReleased(SDL_Keycode key) const { return !IsKeyDown(key) && WasKeyDown(key); }

	private:
		std::list<SDL_Keycode> m_currKeys;
		std::list<SDL_Keycode> m_prevKeys;
	};
}

using engine::InputManager;

#endif
