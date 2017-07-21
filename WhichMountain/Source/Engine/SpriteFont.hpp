#pragma once
#ifndef ENGINE_SPRITEFONT_HPP
#define ENGINE_SPRITEFONT_HPP

#include "Sprite.hpp"

#include <glm/glm.hpp>
#include <string>
#include <map>

namespace engine
{
	class SpriteFont
	{
	public:
		explicit SpriteFont(ContentManager& content, std::string basePath, std::string extension);
		SpriteFont(ContentManager& content, std::string basePath, std::string extension, std::string supportedChars);

		void DrawString(std::string text, glm::vec2 position);

	private:
		std::map<char, std::unique_ptr<Sprite>> m_charMap;
	};
}

using engine::SpriteFont;

#endif
