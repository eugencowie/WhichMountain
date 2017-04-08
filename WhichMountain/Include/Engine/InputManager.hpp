#pragma once
#ifndef ENGINE_INPUTMANAGER_HPP
#define ENGINE_INPUTMANAGER_HPP

#include <Engine/Window.hpp>
#include <list>

namespace engine
{
	typedef std::shared_ptr<class InputManager> InputManagerPtr;

	class InputManager
	{
	public:
		static InputManagerPtr Create(WindowPtr window);

		InputManager(WindowPtr window);

		void Update();

		bool IsDown(SDL_Keycode key);
		bool WasDown(SDL_Keycode key);
		bool IsJustPressed(SDL_Keycode key) { return IsDown(key) && !WasDown(key); }
		bool IsJustReleased(SDL_Keycode key) { return !IsDown(key) && WasDown(key); }

	private:
		WindowPtr m_window;

		std::list<SDL_Keycode> m_currKeys;
		std::list<SDL_Keycode> m_prevKeys;
	};
}

using engine::InputManagerPtr;
using engine::InputManager;

#endif
