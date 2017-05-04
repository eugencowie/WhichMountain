#include "Rectangle.hpp"

namespace engine
{
	Rectangle::Rectangle(glm::vec2 position, glm::vec2 size) :
		m_position(position), m_size(size)
	{
	}

	bool Rectangle::Contains(glm::vec2 point)
	{
		bool containsX = (m_position.x <= point.x && point.x <= m_position.x + m_size.x);
		bool containsY = (m_position.y <= point.y && point.y <= m_position.y + m_size.y);

		return (containsX && containsY);
	}

	bool Rectangle::Intersects(Rectangle other)
	{
		bool intersectsX = (other.GetLeft() <= GetRight() && other.GetRight() >= GetLeft());
		bool intersectsY = (other.GetTop() <= GetBottom() && other.GetBottom() >= GetTop());

		return (intersectsX && intersectsY);
	}
}
