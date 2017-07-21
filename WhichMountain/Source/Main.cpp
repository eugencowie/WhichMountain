#include "Engine/Engine.hpp"
#include "Game/Game.hpp"

// SDL redefines main ಠ_ಠ
#undef main

/**
 * The entry point of the application.
 */
int main(int argc, char** argv)
{
	// Initialise SDL.
	Engine::Initialise();

	// Run the game.
	Game().Run();

	// Clean up SDL.
	Engine::Finalise();

	return 0;
}
