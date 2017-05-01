#pragma once
#ifndef GAME_OBJECTS_PLAYER_HPP
#define GAME_OBJECTS_PLAYER_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/Model.hpp"

#include <glm/glm.hpp>

namespace game
{
	namespace objects
	{
		class Player
		{
		public:
			explicit Player(ContentManager* content, InputManager* input);

			void Update(int elapsedTime);
			void Draw(glm::mat4 view, glm::mat4 proj);

			glm::vec3 GetPosition() const { return m_position; }

		private:
			InputManager* m_input;

			ModelPtr m_model;

			glm::vec3 m_position;
		};
	}
}

using game::objects::Player;

#endif
