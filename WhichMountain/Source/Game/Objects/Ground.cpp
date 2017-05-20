#include "Ground.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace game
{
	namespace objects
	{
		Ground::Ground(ContentManager* content)
		{
			auto shader = content->GetShader("Shaders/Textured");

			std::vector<Vertex> vertices = {
				{ {-10,-1,-10}, {}, {0,0} },
				{ { 10,-1,-10}, {}, {1,0} },
				{ { 10,-1, 10}, {}, {1,1} },
				{ {-10,-1, 10}, {}, {0,1} },
			};

			std::vector<GLuint> indices = {
				3,2,1,
				1,0,3
			};

			TexturePtr texture = content->GetTexture("Textures/Ground.jpg", TextureType::DIFFUSE);

			m_mesh = Mesh::Create(shader, vertices, indices, {texture});
		}

		void Ground::Update(glm::vec3 playerPosition)
		{
			if (playerPosition.z < m_position.z - 10)
			{
				m_position.z -= 10;
			}

			if (playerPosition.x < m_position.x - 10)
			{
				m_position.x -= 10;
			}

			if (playerPosition.x > m_position.x + 10)
			{
				m_position.x += 10;
			}
		}

		void Ground::Draw(glm::mat4 view, glm::mat4 proj)
		{
			glm::mat4 model = glm::translate(glm::mat4(), m_position);

			for (int x = -5; x < 5; ++x)
			{
				for (int z = -5; z < 5; ++z)
				{
					m_mesh->Draw(glm::translate(model, glm::vec3(x*20,0,z*20)), view, proj);
				}
			}
		}
	}
}
