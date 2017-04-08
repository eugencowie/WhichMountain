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
		static TexturePtr Create(const char* path, TextureType type, bool flipUVs=false) {
			return std::make_shared<Texture>(path, type, flipUVs);
		}

		Texture(const char* path, TextureType type, bool flipUVs=false);
		Texture(const Texture&) = delete;
		~Texture();

		GLuint GetTexture() const { return m_texture; }
		TextureType GetType() const { return m_type; }
		std::string GetPath() const { return m_path; }

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
