#include <Engine/Window.hpp>

#include <GL/glew.h>
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
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

		if (!m_window)
		{
			assert(0 && "Failed to create SDL window");
			std::exit(EXIT_FAILURE);
		}

		SDL_GLContext context = SDL_GL_CreateContext(m_window);

		if (!context)
		{
			assert(0 && "Failed to create OpenGL context");
			std::exit(EXIT_FAILURE);
		}

		GLenum result = glewInit();

		if (result != GLEW_OK)
		{
			assert(0 && "Failed to load OpenGL");
			std::exit(EXIT_FAILURE);
		}

		if (!GLEW_VERSION_2_1 || !GLEW_ARB_vertex_array_object)
		{
			assert(0 && "OpenGL version does not meet requirements");
			std::exit(EXIT_FAILURE);
		}

		m_shouldClose = false;
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_window);
	}

	void Window::ProcessEvents()
	{
		m_events.clear();

		SDL_Event e;

		while (SDL_PollEvent(&e))
		{
			m_events.push_back(e);

			switch (e.type)
			{
				case SDL_QUIT:
					Close();
					break;
			}
		}
	}

	std::vector<SDL_Event> Window::GetEvents()
	{
		return m_events;
	}

	void Window::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_window);
	}

	int Window::GetTicks()
	{
		return SDL_GetTicks();
	}

	void Window::VerticalSync(bool vsync)
	{
		SDL_GL_SetSwapInterval(vsync ? 1 : 0);
	}

	void Window::CaptureMouse(bool captureMouse)
	{
		SDL_SetRelativeMouseMode(captureMouse ? SDL_TRUE : SDL_FALSE);
	}
}
