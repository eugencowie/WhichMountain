#pragma once
#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "ContentManager.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"

#include <glm/glm.hpp>

namespace engine
{
	class Sprite
	{
	public:
		Sprite(ShaderPtr shader, TexturePtr texture, glm::vec2 screen, glm::vec2 origin={});
		Sprite(ContentManager* content, const char* shader, const char* texture, glm::vec2 screen, glm::vec2 origin={});

		void Draw(glm::vec2 position);

		glm::vec2 GetSize() const { return m_texture->GetSize(); }
		glm::vec2 GetOffset() const { return GetSize() * m_origin; }

	private:
		glm::vec2 FlipY(glm::vec2 v) const { return v * glm::vec2(1, -1); }
		glm::vec2 ToUnits(glm::vec2 pixels) const { return pixels / m_screen; }
		glm::vec2 ToPixels(glm::vec2 units) const { return units * m_screen; }
		glm::vec3 ToVec3(glm::vec2 v) const { return glm::vec3(v, 0); }

		glm::vec2 m_screen;
		glm::vec2 m_origin;

		TexturePtr m_texture;
		MeshPtr m_mesh;
	};
}

using engine::Sprite;

#endif
