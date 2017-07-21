#pragma once
#ifndef ENGINE_CONTENTMANAGER_HPP
#define ENGINE_CONTENTMANAGER_HPP

#include "Shader.hpp"
#include "Texture.hpp"
#include "Model.hpp"

#include <map>
#include <string>

namespace engine
{
	class ContentManager
	{
	public:
		explicit ContentManager(const char* baseDir);

		ShaderPtr GetShader(std::string vertexPath, std::string fragmentPath);
		ShaderPtr GetShader(std::string path);
		TexturePtr GetTexture(std::string path, TextureType type, bool flipUVs=false);
		ModelPtr GetModel(ShaderPtr shader, std::string path);
		ModelPtr GetModel(std::string shaderPath, std::string path);

	private:
		std::map<std::string, ShaderPtr> m_shaders;
		std::map<std::string, TexturePtr> m_textures;
		std::map<std::string, ModelPtr> m_models;
		std::string m_baseDir;
	};
}

using engine::ContentManager;

#endif
