#pragma once
#ifndef ENGINE_BOUNDINGBOX_HPP
#define ENGINE_BOUNDINGBOX_HPP

#include <glm/glm.hpp>

namespace engine
{
	class BoundingBox
	{
	public:
		BoundingBox(glm::vec3 position, glm::vec3 size);

		bool Contains(glm::vec3 point);
		bool Intersects(BoundingBox other);

		glm::vec3 GetPosition() const { return m_position; }
		glm::vec3 GetSize() const { return m_size; }

		void SetPosition(glm::vec3 position) { m_position = position; }
		void SetSize(glm::vec3 size) { m_size = size; }

		float GetLeft() const { return m_position.x; }
		float GetBottom() const { return m_position.y; }
		float GetRear() const { return m_position.z; }
		float GetRight() const { return m_position.x + m_size.x; }
		float GetTop() const { return m_position.y + m_size.y; }
		float GetFront() const { return m_position.z + m_size.z; }

	private:
		glm::vec3 m_position;
		glm::vec3 m_size;
	};
}

using engine::BoundingBox;

#endif
