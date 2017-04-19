#include "Player.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	namespace objects
	{
		Player::Player(ContentManager* content) :
			m_model(content->GetModel("Shaders/Textured", "Models/RetroRacer/RetroRacer.obj"))
		{
		}

		void Player::Update(int elapsedTime)
		{
			m_position.z += elapsedTime / 160.f;
		}

		void Player::Draw(glm::mat4 view, glm::mat4 proj)
		{
			glm::mat4 model = glm::translate(glm::mat4(), m_position);

			m_model->Draw(model, view, proj);
		}
	}
}
