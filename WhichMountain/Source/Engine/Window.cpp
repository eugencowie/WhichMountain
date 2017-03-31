#include <Engine/Window.hpp>
#include <cassert>
#include <cstdlib>

namespace engine
{
	WindowPtr Window::Create(const char* title, int width, int height)
	{
		return std::make_shared<Window>(title, width, height);
	}

	Window::Window(const char* title, int width, int height)
	{
		m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, NULL);

		if (!m_window)
		{
			assert(0 && "Failed to create SDL window");
			std::exit(-1);
		}

		m_shouldClose = false;
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_window);
	}

	void Window::ProcessEvents()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:
					Close();
					break;
			}
		}
	}

	int Window::GetTicks()
	{
		return SDL_GetTicks();
	}
}
