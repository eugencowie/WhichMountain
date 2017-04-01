#include <Engine/Mesh.hpp>

#include <glm/gtc/type_ptr.hpp>
#include <string>

namespace engine
{
	MeshPtr Mesh::Create(ShaderPtr shader, std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<TexturePtr> textures)
	{
		return std::make_shared<Mesh>(shader, vertices, indices, textures);
	}

	Mesh::Mesh(ShaderPtr shader, std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<TexturePtr> textures)
	{
		m_vertices = vertices;
		m_indices = indices;
		m_textures = textures;

		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);

		glGenBuffers(1, &m_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glGenBuffers(1, &m_elementBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

		glBindVertexArray(0);

		BindShader(shader);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_elementBuffer);
		glDeleteBuffers(1, &m_vertexBuffer);
		glDeleteVertexArrays(1, &m_vertexArray);
	}

	void Mesh::BindShader(ShaderPtr shader)
	{
		m_shader = shader;

		glBindVertexArray(m_vertexArray);

		GLuint positionLoc = m_shader->GetAttribLocation("v_position");
		glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		glEnableVertexAttribArray(positionLoc);

		GLuint normalLoc = m_shader->GetAttribLocation("v_normal");
		glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		glEnableVertexAttribArray(normalLoc);

		GLuint texCoordLoc = m_shader->GetAttribLocation("v_texCoord");
		glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoord));
		glEnableVertexAttribArray(texCoordLoc);

		glBindVertexArray(0);
	}

	void Mesh::Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
	{
		m_shader->Use();

		int diffuseCount = 0;
		int specularCount = 0;
		for (unsigned int i = 0; i < m_textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			std::string name;

			if (m_textures[i]->GetType() == TextureType::DIFFUSE)
			{
				name = "texture_diffuse" + std::to_string(diffuseCount++);
			}
			else if (m_textures[i]->GetType() == TextureType::SPECULAR)
			{
				name = "texture_specular" + std::to_string(specularCount++);
			}

			m_shader->SetUniform(name.c_str(), i);

			glBindTexture(GL_TEXTURE_2D, m_textures[i]->GetTexture());
		}
		glActiveTexture(GL_TEXTURE0);

		m_shader->SetUniform("modelViewProjection", projection * view * model);
		m_shader->SetUniform("projection", projection);
		m_shader->SetUniform("view", view);
		m_shader->SetUniform("model", model);

		glBindVertexArray(m_vertexArray);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBuffer);
		glDrawElements(GL_TRIANGLES, (GLsizei)m_indices.size(), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
}
