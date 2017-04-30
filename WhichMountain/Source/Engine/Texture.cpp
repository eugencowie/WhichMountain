#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <cassert>

namespace engine
{
	Texture::Texture(const char* path, TextureType type, bool flipUVs)
	{
		m_path = path;
		m_type = type;

		stbi_set_flip_vertically_on_load(flipUVs);

		int width, height;
		unsigned char* image = stbi_load(path, &width, &height, nullptr, STBI_rgb_alpha);

		if (!image)
		{
			assert(false && "Failed to load texture image");
			std::exit(EXIT_FAILURE);
		}

		m_size = glm::vec2(width, height);

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(image);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_texture);
	}
}
