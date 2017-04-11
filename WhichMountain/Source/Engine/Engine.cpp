#include "Engine.hpp"

#include <SDL.h>
#include <cstdlib>
#include <cassert>

namespace engine
{
	void Engine::Initialise()
	{
		int result = SDL_Init(SDL_INIT_EVERYTHING);

		if (result != 0)
		{
			assert(false && "Failed to initialise SDL");
			std::exit(EXIT_FAILURE);
		}
	}

	void Engine::Finalise()
	{
		SDL_Quit();
	}
}
