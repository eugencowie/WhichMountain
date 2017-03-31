#pragma once
#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include <SDL.h>
#include <memory>

namespace engine
{
	typedef std::shared_ptr<class Window> WindowPtr;

	class Window
	{
	public:
		static WindowPtr Create(const char* title, int width, int height);

		Window(const char* title, int width, int height);
		~Window();

		void ProcessEvents();

		int GetTicks();

		void Close(bool shouldClose=true) { m_shouldClose = shouldClose; }
		bool ShouldClose() { return m_shouldClose; }

	private:
		SDL_Window* m_window;
		bool m_shouldClose;
	};
}

using engine::WindowPtr;
using engine::Window;

#endif
