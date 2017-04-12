#pragma once
#ifndef GAME_OBJECTS_PLAYER_HPP
#define GAME_OBJECTS_PLAYER_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Model.hpp"

namespace game
{
	namespace objects
	{
		class Player
		{
		public:
			explicit Player(ContentManager* content);

			void Draw(int elapsedTime, glm::mat4 view, glm::mat4 proj);

		private:
			ModelPtr m_model;
			float m_rotation;
		};
	}
}

using game::objects::Player;

#endif
