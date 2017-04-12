#include "Player.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	namespace objects
	{
		Player::Player(ContentManager* content)
		{
			auto shader = content->GetShader("Shaders/Textured");
			m_model = content->GetModel(shader, "Models/RetroRacer/RetroRacer.obj");
			m_rotation = 0;
		}

		void Player::Draw(int elapsedTime, glm::mat4 view, glm::mat4 proj)
		{
			m_rotation += glm::radians(elapsedTime / 25.f);

			glm::mat4 model = glm::rotate(glm::mat4(), m_rotation, glm::vec3(0, 1, 0));

			m_model->Draw(model, view, proj);
		}
	}
}
