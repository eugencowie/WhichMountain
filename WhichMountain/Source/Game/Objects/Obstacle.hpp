#pragma once
#ifndef GAME_OBJECTS_OBSTACLE_HPP
#define GAME_OBJECTS_OBSTACLE_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Model.hpp"

#include <glm/glm.hpp>

namespace game
{
	namespace objects
	{
		class Obstacle
		{
		public:
			explicit Obstacle(ContentManager* content, glm::vec3 position, glm::vec3 size);

			void Draw(glm::mat4 view, glm::mat4 proj);

		private:
			ModelPtr m_model;

			glm::vec3 m_position;
			glm::vec3 m_size;
		};
	}
}

using game::objects::Obstacle;

#endif
