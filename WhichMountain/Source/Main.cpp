#include "Engine/Engine.hpp"
#include "Game/Game.hpp"

// SDL redefines main ಠ_ಠ
#undef main

int main(int argc, char** argv)
{
	Engine::Initialise();

	Game().Run();

	Engine::Finalise();

	return 0;
}
