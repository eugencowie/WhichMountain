#pragma once
#ifndef GAME_OBJECTS_PICKUPS_HPP
#define GAME_OBJECTS_PICKUPS_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Model.hpp"
#include "../../Engine/BoundingBox.hpp"

#include <glm/glm.hpp>

namespace game
{
	namespace objects
	{
		class Pickup
		{
		public:
			Pickup(ContentManager& content, glm::vec3 position, glm::vec3 size = {1,1,1});

			void Draw(glm::mat4 view, glm::mat4 proj);

			BoundingBox GetBounds() const { return {m_position - (m_size/2.0f), m_size}; }

		private:
			ModelPtr m_model;

			glm::vec3 m_position;
			glm::vec3 m_size;
		};
	}
}

using game::objects::Pickup;

#endif
