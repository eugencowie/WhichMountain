#include "BoundingBox.hpp"

namespace engine
{
	BoundingBox::BoundingBox(glm::vec3 position, glm::vec3 size) :
		m_position(position),
		m_size(size)
	{
	}

	bool BoundingBox::Contains(glm::vec3 point)
	{
		bool containsX = (GetLeft() <= point.x && point.x <= GetRight());
		bool containsY = (GetBottom() <= point.y && point.y <= GetTop());
		bool containsZ = (GetRear() <= point.z && point.z <= GetFront());

		return (containsX && containsY && containsZ);
	}

	bool BoundingBox::Intersects(BoundingBox other)
	{
		bool intersectsX = (other.GetLeft() <= GetRight() && other.GetRight() >= GetLeft());
		bool intersectsY = (other.GetBottom() <= GetTop() && other.GetTop() >= GetBottom());
		bool intersectsZ = (other.GetRear() <= GetFront() && other.GetFront() >= GetRear());

		return (intersectsX && intersectsY && intersectsZ);
	}
}
