#include "Player.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/compatibility.hpp>

namespace game
{
	namespace objects
	{
		Player::Player(ContentManager& content, InputManager& input, AudioManager& audio) :
			m_input(input),
			m_audio(audio),
			m_model(content.GetModel("Shaders/Textured", "Models/RetroRacer/RetroRacer.obj")),
			m_velocity(0, 0, -0.25f),
			m_state(State::GROUNDED),
			m_targetStrafe(0),
			m_slowDown(0),
			m_speed(60),
			m_speedCooldown(5000)
		{
		}

		void Player::Update(int elapsedTime)
		{
			// Speed

			m_speedCooldown -= elapsedTime;
			if (m_speedCooldown <= 0)
			{
				m_speed += 10;
				m_speedCooldown = 5000;
			}

			/*if (speedMultiplier <= 1)
			{
				speedMultiplier = 1;
			}
			if (speedMultiplier <= m_slowDown)
			{
				m_slowDown = speedMultiplier - 1;
			}*/

			m_velocity.z = m_speed * -0.01f;

			// Strafing

			m_targetStrafe = 0;
			if (m_input.IsKeyDown(SDLK_LEFT) || m_input.IsKeyDown(SDLK_a))
			{
				m_targetStrafe = m_velocity.z;
			}
			else if (m_input.IsKeyDown(SDLK_RIGHT) || m_input.IsKeyDown(SDLK_d))
			{
				m_targetStrafe = -m_velocity.z;
			}

			// Jumping/falling

			float floorHeight = 0;
			float jumpSpd = 0.2f;
			float gravity = 0.005f;

			if (m_state == State::GROUNDED)
			{
				if (m_input.IsKeyJustPressed(SDLK_SPACE))
				{
					m_velocity.y = jumpSpd;
					m_state = State::JUMPING;
					m_audio.PlaySound("Content/Audio/Jump.wav");
				}
			}
			else if (m_state == State::JUMPING)
			{
				m_velocity.y -= gravity;

				if (m_velocity.y <= 0)
				{
					m_state = State::FALLING;
				}
			}
			else if (m_state == State::FALLING)
			{
				m_velocity.y -= gravity;

				if (m_position.y < floorHeight)
				{
					m_position.y = floorHeight;
					m_velocity.y = 0;
					m_state = State::GROUNDED;
				}
			}

			//

			m_velocity.x = m_targetStrafe;

			m_position += m_velocity;
		}

		void Player::Draw(glm::mat4 view, glm::mat4 proj) const
		{
			glm::mat4 model = glm::translate(glm::mat4(), m_position);

			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

			m_model->Draw(model, view, proj);
		}
	}
}
