#include "Ground.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace game
{
	namespace objects
	{
		Ground::Ground(ContentManager* content, float size) :
			m_position(0, -1, 0),
			m_size(size)
		{
			auto shader = content->GetShader("Shaders/Textured");

			float half = m_size / 2.0f;
			std::vector<Vertex> vertices = {
				{ {-half,0,-half}, {}, {0,0} },
				{ { half,0,-half}, {}, {1,0} },
				{ { half,0, half}, {}, {1,1} },
				{ {-half,0, half}, {}, {0,1} },
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
			float half = m_size / 2.0f;

			if (playerPosition.z < m_position.z - half)
			{
				m_position.z -= half;
			}
			else if (playerPosition.z > m_position.z + half)
			{
				m_position.z += half;
			}

			if (playerPosition.x < m_position.x - half)
			{
				m_position.x -= half;
			}
			else if (playerPosition.x > m_position.x + half)
			{
				m_position.x += half;
			}
		}

		void Ground::Draw(glm::mat4 view, glm::mat4 proj)
		{
			// Draw the ground as a 6x6 grid.
			static const int halfGrid = 3;
			for (int x = -halfGrid; x <= halfGrid; ++x)
			{
				for (int z = -halfGrid; z <= halfGrid; ++z)
				{
					glm::mat4 model = glm::translate(glm::mat4(), m_position + glm::vec3(x * m_size, 0, z * m_size));
					m_mesh->Draw(model, view, proj);
				}
			}
		}
	}
}
