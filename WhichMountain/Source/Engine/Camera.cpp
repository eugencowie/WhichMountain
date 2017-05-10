#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/compatibility.hpp>

namespace engine
{
	Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up) :
		m_position(position),
		m_target(target),
		m_up(up)
	{
	}

	glm::mat4 Camera::GetMatrix() const
	{
		return glm::lookAt(m_position, m_target, m_up);
	}

	FollowCamera::FollowCamera(glm::vec3 offset, glm::vec3 target, glm::vec3 up) :
		Camera(target + offset, target, up), m_offset(offset)
	{
	}

	void FollowCamera::Update(glm::vec3 target)
	{
		//glm::vec3 desiredPos = target + m_offset;
		//glm::vec3 actualPos = glm::lerp(GetPosition(), desiredPos, 0.25f);
		//SetPosition(actualPos);

		SetPosition(target + m_offset);
		SetTarget(target);
	}
}
