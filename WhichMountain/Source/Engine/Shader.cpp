#include <Engine/Shader.hpp>

#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <cassert>

namespace engine
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::ifstream vertexStream(vertexPath);
		std::string vertexSource = { std::istreambuf_iterator<GLchar>(vertexStream), std::istreambuf_iterator<GLchar>() };

		if (vertexSource.empty())
		{
			assert(false && "Failed to load vertex shader from file");
			std::exit(EXIT_FAILURE);
		}

		const GLchar* vertexSourceStr = vertexSource.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSourceStr, nullptr);
		glCompileShader(vertexShader);

		GLint vertexSuccess;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);

		if (!vertexSuccess)
		{
			assert(false && "Failed to compile vertex shader");
			std::exit(EXIT_FAILURE);
		}

		//

		std::ifstream fragmentStream(fragmentPath);
		std::string fragmentSource = std::string{ std::istreambuf_iterator<GLchar>(fragmentStream), std::istreambuf_iterator<GLchar>() };

		if (fragmentSource.empty())
		{
			assert(false && "Failed to load fragment shader from file");
			std::exit(EXIT_FAILURE);
		}

		const GLchar* fragmentSourceStr = fragmentSource.c_str();

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSourceStr, nullptr);
		glCompileShader(fragmentShader);

		GLint fragmentSuccess;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);

		if (!fragmentSuccess)
		{
			assert(false && "Failed to compile fragment shader");
			std::exit(EXIT_FAILURE);
		}

		//

		m_program = glCreateProgram();
		glAttachShader(m_program, vertexShader);
		glAttachShader(m_program, fragmentShader);
		glLinkProgram(m_program);

		GLint programSuccess;
		glGetShaderiv(m_program, GL_LINK_STATUS, &programSuccess);

		if (!programSuccess)
		{
			assert(false && "Failed to link vertex and fragment shaders");
			std::exit(EXIT_FAILURE);
		}

		//

		glDetachShader(m_program, fragmentShader);
		glDetachShader(m_program, vertexShader);

		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);
	}

	Shader::~Shader()
	{
		glDeleteShader(m_program);
	}

	void Shader::Use()
	{
		glUseProgram(m_program);
	}

	GLuint Shader::GetUniformLocation(const char* name)
	{
		return glGetUniformLocation(m_program, name);
	}

	GLuint Shader::GetAttribLocation(const char* name)
	{
		return glGetAttribLocation(m_program, name);
	}

	void Shader::SetUniform(const char* name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetUniform(const char* name, const float* value, int count, bool transpose)
	{
		glUniformMatrix4fv(GetUniformLocation(name), count, transpose, value);
	}

	void Shader::SetUniform(const char* name, glm::mat4 value, bool transpose)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, transpose, glm::value_ptr(value));
	}
}
