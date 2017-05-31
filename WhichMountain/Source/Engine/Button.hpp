#pragma once
#ifndef ENGINE_BUTTON_HPP
#define ENGINE_BUTTON_HPP

#include "ContentManager.hpp"
#include "InputManager.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "Rectangle.hpp"

#include <glm/glm.hpp>

namespace engine
{
	class Button
	{
	public:
		Button(Sprite sprite, Sprite hover, glm::vec2 position);
		Button(ShaderPtr shader, TexturePtr texture, TexturePtr hover, glm::vec2 position, glm::vec2 screen, glm::vec2 origin={});
		Button(ContentManager& content, const char* shader, const char* texture, const char* hover, glm::vec2 position, glm::vec2 screen, glm::vec2 origin={});

		void Update(InputManager& input);
		void Draw();

		bool IsClicked() const { return (m_state == ButtonState::CLICKED); }

		void SetPosition(glm::vec2 position) { m_bounds.SetPosition(position - m_sprite.GetOffset()); }

	private:
		enum class ButtonState { NOT_PRESSED, PRESSED, CLICKED };

		Sprite m_sprite;
		Sprite m_hover;
		Rectangle m_bounds;
		bool m_hovering;

		ButtonState m_state;
	};
}

using engine::Button;

#endif
