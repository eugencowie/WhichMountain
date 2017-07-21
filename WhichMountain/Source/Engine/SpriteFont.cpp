#include "SpriteFont.hpp"

namespace engine
{
	SpriteFont::SpriteFont(ContentManager& content, std::string basePath, std::string extension) :
		SpriteFont(content, basePath, extension, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")
	{
	}

	SpriteFont::SpriteFont(ContentManager& content, std::string basePath, std::string extension, std::string supportedChars)
	{
		for (auto c : supportedChars)
		{
			m_charMap[c] = std::make_unique<Sprite>(content, "Shaders/Textured", (basePath + c + extension).c_str(), glm::vec2(1280, 720), glm::vec2());
		}
	}

	void SpriteFont::DrawString(std::string text, glm::vec2 position)
	{
		for (auto c : text)
		{
			auto it = m_charMap.find(c);
			if (it != m_charMap.end())
			{
				it->second->Draw(position, 0.5f);
			}

			position.x += 20;
		}
	}
}
