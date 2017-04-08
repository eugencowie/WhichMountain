#pragma once
#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include <SDL.h>
#include <vector>

namespace engine
{
	class Window
	{
	public:
		Window(const char* title, int width, int height);
		Window(const Window&) = delete;
		~Window();

		void ProcessEvents();

		void SwapBuffers();

		int GetTicks();

		void VerticalSync(bool vsync=true);
		void CaptureMouse(bool captureMouse=true);

		void Close(bool shouldClose=true) { m_shouldClose = shouldClose; }
		bool ShouldClose() const { return m_shouldClose; }

		std::vector<SDL_Event> GetEvents() const { return m_events; }

	private:
		SDL_Window* m_window;
		bool m_shouldClose;

		std::vector<SDL_Event> m_events;
	};
}

using engine::Window;

#endif
