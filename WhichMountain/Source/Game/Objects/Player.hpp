#pragma once
#ifndef GAME_OBJECTS_PLAYER_HPP
#define GAME_OBJECTS_PLAYER_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/AudioManager.hpp"
#include "../../Engine/Model.hpp"
#include "../../Engine/BoundingBox.hpp"

#include <glm/glm.hpp>

namespace game
{
	namespace objects
	{
		class Player
		{
		public:
			Player(ContentManager* content, InputManager* input, AudioManager* audio);

			void Update(int elapsedTime);
			void Draw(glm::mat4 view, glm::mat4 proj) const;

			glm::vec3 GetPosition() const { return m_position; }
			BoundingBox GetBounds() const { return {m_position - 1.0f, glm::vec3(2.0f)}; }

		private:
			InputManager* m_input;
			AudioManager* m_audio;

			ModelPtr m_model;
			glm::vec3 m_position;
			glm::vec3 m_velocity;
			float m_targetStrafe;

			enum class State { GROUNDED, JUMPING, FALLING };
			State m_state;
		};
	}
}

using game::objects::Player;

#endif
