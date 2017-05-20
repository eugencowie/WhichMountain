#pragma once
#ifndef ENGINE_RECTANGLE_HPP
#define ENGINE_RECTANGLE_HPP

#include <glm/glm.hpp>

namespace engine
{
	class Rectangle
	{
	public:
		Rectangle(glm::vec2 position, glm::vec2 size);

		bool Contains(glm::vec2 point);
		bool Intersects(Rectangle other);

		glm::vec2 GetPosition() const { return m_position; }
		glm::vec2 GetSize() const { return m_size; }

		void SetPosition(glm::vec2 position) { m_position = position; }
		void SetSize(glm::vec2 size) { m_size = size; }

		float GetLeft() const { return m_position.x; }
		float GetTop() const { return m_position.y; }
		float GetRight() const { return m_position.x + m_size.x; }
		float GetBottom() const { return m_position.y + m_size.y; }

	private:
		glm::vec2 m_position;
		glm::vec2 m_size;
	};
}

#endif
