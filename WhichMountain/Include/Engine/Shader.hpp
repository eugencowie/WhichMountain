#pragma once
#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>

namespace engine
{
	typedef std::shared_ptr<class Shader> ShaderPtr;

	class Shader
	{
	public:
		static ShaderPtr Create(const char* vertexPath, const char* fragmentPath) {
			return std::make_shared<Shader>(vertexPath, fragmentPath);
		}

		Shader(const char* vertexPath, const char* fragmentPath);
		Shader(const Shader&) = delete;
		~Shader();

		void Use();

		GLuint GetUniformLocation(const char* name);
		GLuint GetAttribLocation(const char* name);

		void SetUniform(const char* name, int value);
		void SetUniform(const char* name, const float* value, int count=1, bool transpose=false);
		void SetUniform(const char* name, glm::mat4 value, bool transpose=false);

	private:
		GLuint m_program;
	};
}

using engine::ShaderPtr;
using engine::Shader;

#endif
