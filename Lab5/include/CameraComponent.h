/**
@file CameraComponent.h
*/

#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

class CameraComponent : public Component
{
public:
	glm::vec3 m_position;	   //!< Holds the position of the camera
	glm::quat m_orientation;   //!< Holds the orientation of the camera	
	float m_fov;               //!< The field of view of the camera
	
	CameraComponent() : m_position(0), m_orientation(1,0,0,0), m_fov(45) {}     //!< Sets the starting position, orientation and fov of the camera
	CameraComponent(const glm::vec3& pos) : m_position(pos), m_orientation(1, 0, 0, 0),m_fov(45) {}
	CameraComponent(const glm::vec3& pos, const glm::quat& orient) : m_position(pos), m_orientation(orient), m_fov(45) {}

	void lookAt(const glm::vec3& target) { m_orientation = (glm::toQuat(glm::lookAt(m_position, target, glm::vec3(0, 1, 0)))); }
	
	const glm::vec3& position() const { return m_position; }
	const glm::quat& orientation() const { return m_orientation; }

	// Add the setters
	void setPosition(const glm::vec3 newPosition)   //!< Sets a new position of the camera when called
	{
		m_position = newPosition;
	}
	void setOrientation(const glm::quat newOrientation)		//!< Sets a new orientation of the camera when called
	{
		m_orientation = newOrientation;
	}

	glm::mat4 getViewMatrix() const 
	{ 
		return glm::translate(glm::mat4_cast(inverse(m_orientation)), -m_position);		//!< Returns the view matrix of the camera
	}
	
	void translate(const glm::vec3 &v) { m_position += v * m_orientation; }
	void translate(float x, float y, float z) { m_position += glm::vec3(x, y, z) * m_orientation; }

	void rotate(float angle, const glm::vec3 &axis) { m_orientation *= glm::angleAxis(angle, axis * m_orientation); }
	void rotate(float angle, float x, float y, float z) { m_orientation *= glm::angleAxis(angle, glm::vec3(x, y, z) * m_orientation); }

	void yaw(float angle) { rotate(angle, 0.0f, 1.0f, 0.0f); }
	void pitch(float angle) { rotate(angle, 1.0f, 0.0f, 0.0f); }
	void roll(float angle) { rotate(angle, 0.0f, 0.0f, 1.0f); }

	void setFOV(float fov) { m_fov = fov; }

	void OnUpdate(float dt) override
	{

	}
	void OnMessage(const std::string m) override
	{

	}
};
