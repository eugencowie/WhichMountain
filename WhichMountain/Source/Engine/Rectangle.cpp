#include "Rectangle.hpp"

namespace engine
{
	Rectangle::Rectangle(glm::vec2 position, glm::vec2 size) :
		m_position(position), m_size(size)
	{
	}

	bool Rectangle::Contains(glm::vec2 point)
	{
		bool containsX = (GetLeft() <= point.x && point.x <= GetRight());
		bool containsY = (GetTop() <= point.y && point.y <= GetBottom());

		return (containsX && containsY);
	}

	bool Rectangle::Intersects(Rectangle other)
	{
		bool intersectsX = (other.GetLeft() <= GetRight() && other.GetRight() >= GetLeft());
		bool intersectsY = (other.GetTop() <= GetBottom() && other.GetBottom() >= GetTop());

		return (intersectsX && intersectsY);
	}
}
