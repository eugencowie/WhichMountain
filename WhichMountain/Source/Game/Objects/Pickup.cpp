#include "Pickup.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	namespace objects
	{
		Pickup::Pickup(ContentManager& content, glm::vec3 position, glm::vec3 size) :
			m_model(content.GetModel("Shaders/Textured", "Models/Pickups/Pickup_1.obj")),
			m_position(position),
			m_size(size)
		{
		}

		void Pickup::Draw(glm::mat4 view, glm::mat4 proj)
		{
			glm::mat4 model = glm::scale(glm::mat4(), m_size);
			model = glm::translate(model, m_position);

			m_model->Draw(model, view, proj);
		}
	}
}
