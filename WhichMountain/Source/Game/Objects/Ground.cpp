#include "Ground.hpp"

#include <vector>

namespace game
{
	namespace objects
	{
		Ground::Ground(ContentManager* content)
		{
			auto shader = content->GetShader("Shaders/Textured");

			std::vector<Vertex> vertices = {
			};

			std::vector<GLuint> indices = {
			};

			std::vector<TexturePtr> textures = {
			};

			//m_mesh = Mesh::Create(shader, vertices, indices, textures);
		}

		void Ground::Draw(glm::mat4 view, glm::mat4 proj)
		{
			//m_mesh->Draw({}, view, proj);
		}
	}
}
