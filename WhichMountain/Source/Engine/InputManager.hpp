#pragma once
#ifndef ENGINE_INPUTMANAGER_HPP
#define ENGINE_INPUTMANAGER_HPP

#include <SDL.h>
#include <glm/glm.hpp>
#include <vector>
#include <list>

namespace engine
{
	class InputManager
	{
	public:
		void ProcessEvents(std::vector<SDL_Event> events);

		bool IsKeyDown(SDL_Keycode key) const;
		bool IsBtnDown(Uint8 button) const;

		bool WasKeyDown(SDL_Keycode key) const;
		bool WasBtnDown(Uint8 button) const;

		bool IsKeyJustPressed(SDL_Keycode key) const { return IsKeyDown(key) && !WasKeyDown(key); }
		bool IsBtnJustPressed(Uint8 button) const { return IsBtnDown(button) && !WasBtnDown(button); }

		bool IsKeyJustReleased(SDL_Keycode key) const { return !IsKeyDown(key) && WasKeyDown(key); }
		bool IsBtnJustReleased(Uint8 button) const { return !IsBtnDown(button) && WasBtnDown(button); }

		glm::vec2 GetMousePos() const { return m_currMousePos; }

	private:
		std::list<SDL_Keycode> m_currKeys;
		std::list<SDL_Keycode> m_prevKeys;

		std::list<Uint8> m_currButtons;
		std::list<Uint8> m_prevButtons;

		glm::vec2 m_currMousePos;
		glm::vec2 m_prevMousePos;
	};
}

using engine::InputManager;

#endif
