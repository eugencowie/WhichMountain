#include "Sprite.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
	Sprite::Sprite(ShaderPtr shader, TexturePtr texture, glm::vec2 screen, glm::vec2 origin)
		: m_origin(origin), m_screen(screen), m_texture(texture), m_mesh(Mesh::Create(shader, {
			{ {-1, 1,0 }, {}, {0,0} },
			{ { 1, 1,0 }, {}, {1,0} },
			{ { 1,-1,0 }, {}, {1,1} },
			{ {-1,-1,0 }, {}, {0,1} },
		}, {3,2,1,1,0,3}, {texture}))
	{
	}

	Sprite::Sprite(ContentManager& content, const char* shader, const char* texture, glm::vec2 screenSize, glm::vec2 origin)
		: Sprite(content.GetShader(shader), content.GetTexture(texture, TextureType::DIFFUSE), screenSize, origin)
	{
	}

	void Sprite::Draw(glm::vec2 position, float layer)
	{
		glm::mat4 model;

		// set mesh layer
		model = glm::translate(model, glm::vec3(0, 0, layer));

		// set mesh position
		model = glm::translate(model, ToVec3(ToUnits(FlipY(position * 2.f))));

		// set mesh origin
		model = glm::translate(model, ToVec3(ToUnits(FlipY(GetOffset() * -2.f))));

		// set origin to top-left of mesh
		model = glm::translate(model, ToVec3(ToUnits(FlipY(GetSize()))));

		// move mesh from center to top left of screen
		model = glm::translate(model, ToVec3({-1,1}));

		// scale mesh down to texture size
		model = glm::scale(model, ToVec3(ToUnits(GetSize())));

		glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(), glm::vec3(0, 1, 0));

		glm::mat4 proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

		m_mesh->Draw(model, view, proj);
	}
}
