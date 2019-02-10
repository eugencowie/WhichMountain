#pragma once
#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include <glm/glm.hpp>

namespace engine
{
	class Camera
	{
	public:
		Camera(glm::vec3 position={0,0,-10}, glm::vec3 target={0,0,0}, glm::vec3 up={0,1,0});
		virtual ~Camera() = default;

		glm::mat4 GetMatrix() const;

		glm::vec3 GetPosition() const { return m_position; }

		void SetPosition(glm::vec3 position) { m_position = position; }
		void SetTarget(glm::vec3 target) { m_target = target; }
		void SetUp(glm::vec3 up) { m_up = up; }

	private:
		glm::vec3 m_position;
		glm::vec3 m_target;
		glm::vec3 m_up;
	};

	class FollowCamera : public Camera
	{
	public:
		FollowCamera(glm::vec3 offset, glm::vec3 target={}, glm::vec3 up={0,1,0});

		void Update(glm::vec3 target);

	private:
		glm::vec3 m_offset;
	};
}

using engine::Camera;
using engine::FollowCamera;

#endif
