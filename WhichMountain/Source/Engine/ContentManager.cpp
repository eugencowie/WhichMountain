#include "ContentManager.hpp"

namespace engine
{
	ContentManager::ContentManager(const char* baseDir) :
		m_baseDir(baseDir)
	{
		if (m_baseDir[m_baseDir.length() - 1] != '/')
		{
			m_baseDir += "/";
		}
	}

	ShaderPtr ContentManager::GetShader(std::string vertexPath, std::string fragmentPath)
	{
		std::string key = vertexPath + fragmentPath;

		ShaderPtr result = m_shaders[key];

		if (result == nullptr)
		{
			result = Shader::Create((m_baseDir + vertexPath).c_str(), (m_baseDir + fragmentPath).c_str());
			m_shaders[key] = result;
		}

		return result;
	}

	ShaderPtr ContentManager::GetShader(std::string path)
	{
		return GetShader(path + ".vert", path + ".frag");
	}

	TexturePtr ContentManager::GetTexture(std::string path, TextureType type, bool flipUVs)
	{
		TexturePtr result = m_textures[path];

		if (result == nullptr)
		{
			result = Texture::Create((m_baseDir + path).c_str(), type, flipUVs);
			m_textures[path] = result;
		}

		return result;
	}

	ModelPtr ContentManager::GetModel(ShaderPtr shader, std::string path)
	{
		ModelPtr result = m_models[path];

		if (result == nullptr)
		{
			result = Model::Create(shader, m_baseDir + path);
			m_models[path] = result;
		}

		return result;
	}

	ModelPtr ContentManager::GetModel(std::string shaderPath, std::string path)
	{
		return GetModel(GetShader(shaderPath), path);
	}
}
