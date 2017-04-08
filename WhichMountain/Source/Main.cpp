#include <Engine/Engine.hpp>
#include <Game/Game.hpp>

int main(int argc, char** argv)
{
	Engine::Initialise();

	Game().Run();

	Engine::Finalise();

	return 0;
}
