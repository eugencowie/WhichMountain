#include "Player.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	namespace objects
	{
		Player::Player(ContentManager* content, InputManager* input) :
			m_input(input),
			m_model(content->GetModel("Shaders/Textured", "Models/RetroRacer/RetroRacer.obj"))
		{
		}

		void Player::Update(int elapsedTime)
		{
			m_position.z -= elapsedTime / 160.f;

			if (m_input->IsKeyDown(SDLK_LEFT) || m_input->IsKeyDown(SDLK_a))
			{
				m_position.x -= elapsedTime / 160.0f;
			}

			if (m_input->IsKeyDown(SDLK_RIGHT) || m_input->IsKeyDown(SDLK_d))
			{
				m_position.x += elapsedTime / 160.0f;
			}
		}

		void Player::Draw(glm::mat4 view, glm::mat4 proj) const
		{
			glm::mat4 model = glm::translate(glm::mat4(), m_position);

			model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

			m_model->Draw(model, view, proj);
		}
	}
}
