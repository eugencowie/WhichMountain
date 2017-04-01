#pragma once
#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP

#include <GL/glew.h>
#include <string>
#include <memory>

namespace engine
{
	enum class TextureType { DIFFUSE, SPECULAR };

	typedef std::shared_ptr<class Texture> TexturePtr;

	class Texture
	{
	public:
		static TexturePtr Create(const char* path, TextureType type, bool flipUVs=false);

		Texture(const char* path, TextureType type, bool flipUVs=false);
		~Texture();

		GLuint GetTexture() { return m_texture; }
		TextureType GetType() { return m_type; }
		std::string GetPath() { return m_path; }

	private:
		GLuint m_texture;
		TextureType m_type;
		std::string m_path;
	};
}

using engine::TextureType;
using engine::TexturePtr;
using engine::Texture;

#endif
