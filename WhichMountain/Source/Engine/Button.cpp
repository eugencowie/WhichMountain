#include "Button.hpp"

namespace engine
{
	Button::Button(Sprite sprite, Sprite hover, glm::vec2 position) :
		m_sprite(sprite),
		m_hover(hover),
		m_bounds(position - m_sprite.GetOffset(), sprite.GetSize()),
		m_state(ButtonState::NOT_PRESSED)
	{
	}

	Button::Button(ShaderPtr shader, TexturePtr texture, TexturePtr hover, glm::vec2 position, glm::vec2 screen, glm::vec2 origin) :
		Button(Sprite(shader, texture, screen, origin), Sprite(shader, hover, screen, origin), position)
	{
	}

	Button::Button(ContentManager& content, const char* shader, const char* texture, const char* hover, glm::vec2 position, glm::vec2 screen, glm::vec2 origin) :
		Button(Sprite(content, shader, texture, screen, origin), Sprite(content, shader, hover, screen, origin), position)
	{
	}

	void Button::Update(InputManager& input)
	{
		m_hovering = m_bounds.Contains(input.GetMousePos());

		if (m_state == ButtonState::NOT_PRESSED)
		{
			if (m_hovering && input.IsBtnJustPressed(SDL_BUTTON_LEFT))
			{
				m_state = ButtonState::PRESSED;
			}
		}
		else if (m_state == ButtonState::PRESSED)
		{
			if (!m_hovering)
			{
				m_state = ButtonState::NOT_PRESSED;
			}
			else if (input.IsBtnJustReleased(SDL_BUTTON_LEFT))
			{
				m_state = ButtonState::CLICKED;
			}
		}
		else
		{
			m_state = ButtonState::NOT_PRESSED;
		}
	}

	void Button::Draw()
	{
		if (m_hovering)
		{
			m_hover.Draw(m_bounds.GetPosition() + m_sprite.GetOffset());
		}
		else
		{
			m_sprite.Draw(m_bounds.GetPosition() + m_sprite.GetOffset());
		}
	}
}
