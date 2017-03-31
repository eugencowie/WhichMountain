#pragma once
#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

namespace engine
{
	class Engine
	{
	public:
		static void Initialise();
		static void Finalise();
	};
}

using engine::Engine;

#endif
