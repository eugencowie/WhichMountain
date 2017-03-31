#include <Engine/Engine.hpp>
#include <SDL.h>
#include <cassert>
#include <cstdlib>

namespace engine
{
	void Engine::Initialise()
	{
		int result = SDL_Init(SDL_INIT_EVERYTHING);

		if (result != 0)
		{
			assert(0 && "Failed to initialise SDL");
			std::exit(EXIT_FAILURE);
		}
	}

	void Engine::Finalise()
	{
		SDL_Quit();
	}
}
