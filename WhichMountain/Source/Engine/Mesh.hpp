#pragma once
#ifndef ENGINE_MESH_HPP
#define ENGINE_MESH_HPP

#include "Shader.hpp"
#include "Texture.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <memory>

namespace engine
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoord;
	};

	typedef std::shared_ptr<class Mesh> MeshPtr;

	class Mesh
	{
	public:
		static MeshPtr Create(ShaderPtr shader, std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<TexturePtr> textures) {
			return std::make_shared<Mesh>(shader, vertices, indices, textures);
		}

		Mesh(ShaderPtr shader, std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<TexturePtr> textures);
		Mesh(const Mesh&) = delete;
		~Mesh();

		void BindShader(ShaderPtr shader);

		void Draw(glm::mat4 model={}, glm::mat4 view={}, glm::mat4 projection={});

	private:
		ShaderPtr m_shader;

		std::vector<Vertex> m_vertices;
		std::vector<GLuint> m_indices;
		std::vector<TexturePtr> m_textures;

		GLuint m_vertexArray;
		GLuint m_vertexBuffer;
		GLuint m_elementBuffer;
	};
}

using engine::Vertex;
using engine::MeshPtr;
using engine::Mesh;

#endif
