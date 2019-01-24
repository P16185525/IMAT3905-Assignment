/**
@file TransformComponent.h
*/
#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>


class TransformComponent : public Component
{

	const float rotateAmount = 0.003f;  //!< Sets how fast the model rotates
	const float moveAmount = 0.01f;  //!< Sets how fast the model moves
public:
	glm::vec3 m_position;    //!< Sets the model's position
	glm::quat m_orientation;  //!< Sets the model's orientation
	glm::vec3 m_scale;		//!< Sets the model's scale
	 
	void OnUpdate(float dt) override{}
	void OnMessage(const std::string m) override
	{
		//!< Rotation messages
		if (m == "rotateUp")
		{
			pitch(rotateAmount);
		}
		if (m == "rotateDown")
		{
			pitch(-rotateAmount);
		}
		if (m == "rotateLeft")
		{
			yaw(rotateAmount);
		}
		if (m == "rotateRight")
		{
			yaw(-rotateAmount);
		}
		if (m == "rollLeft")
		{
			roll(rotateAmount);
		}
		if (m == "rollRight")
		{
			roll(-rotateAmount);
		}
		
		//!< Translate messages
		if (m == "increaseX")
		{
			glm::vec3 v = glm::vec3(moveAmount, 0, 0);
			translate(m_orientation * v);
		}
		if (m == "decreaseX")
		{
			glm::vec3 v = glm::vec3(-moveAmount, 0, 0);
			translate(m_orientation * v);
		}
		
		if (m == "increaseY")
		{
			glm::vec3 v = glm::vec3(0, moveAmount, 0);
			translate(m_orientation * v);
		}
		if (m == "decreaseY")
		{
			glm::vec3 v = glm::vec3(0, -moveAmount, 0);
			translate(m_orientation * v);
		}
		if 
			(m == "increaseZ")
		{
			glm::vec3 v = glm::vec3(0, 0, moveAmount);
			translate(m_orientation * v);
		}
		if (m == "decreaseZ")
		{
			glm::vec3 v = glm::vec3(0, 0, -moveAmount);
			translate(m_orientation * v);
		}

		//!< Scale messages
		if (m == "increaseXScale")
		{
			scaleUp(0.01f, 0.0f, 0.0f);
		}
		if (m == "decreaseXScale")
		{
			scaleUp(-0.01f, 0.0f, 0.0f);
		}

		if (m == "increaseYScale")
		{
			scaleUp(0.0f, 0.01f, 0.0f);
		}
		if (m == "decreaseYscale")
		{
			scaleUp(0.0f, -0.01f, 0.0f);
		}
		if
			(m == "increaseZScale")
		{
			scaleUp(0.0f, 0.0f, 0.01f);
		}
		if (m == "decreaseZScale")
		{
			scaleUp(0.0f, 0.0f, -0.01f);
		}
	}

	TransformComponent() : m_position(0), m_orientation(1,0,0,0), m_scale(1.0f) {}
	TransformComponent(const glm::vec3& pos) : m_position(pos), m_orientation(1, 0, 0, 0), m_scale(1.0f) {}
	TransformComponent(const glm::vec3& pos, const glm::quat& orient) : m_position(pos), m_orientation(orient), m_scale(1.0f) {}
	TransformComponent(const glm::vec3& pos, const glm::quat& orient, const glm::vec3& scale) : m_position(pos), m_orientation(orient), m_scale(scale) {}

	const glm::vec3& position() const { return m_position; }
	const glm::quat& orientation() const { return m_orientation; }
	const glm::vec3& scale() const { return m_scale; }

	glm::mat4 getModelMatrix()
	{
		glm::mat4 transMatrix = glm::translate(glm::mat4(1.0f), m_position);
		glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), m_scale);
		glm::mat4 rotMatrix = glm::mat4_cast(m_orientation);
		return transMatrix * rotMatrix * scaleMatrix;
	}

	void translate(const glm::vec3 &v) { m_position += v; }
	void translate(float x, float y, float z) { m_position += glm::vec3(x, y, z); }

	void rotate(float angle, const glm::vec3 &axis) { m_orientation *= glm::angleAxis(angle, axis * m_orientation); }
	void rotate(float angle, float x, float y, float z) { m_orientation *= glm::angleAxis(angle, glm::vec3(x, y, z) * m_orientation); }

	void scaleUp(const glm::vec3 &v) { m_scale += v; }
	void scaleUp(float x, float y, float z) { m_scale += glm::vec3(x, y, z); }

	void yaw(float angle) { rotate(angle, 0.0f, 1.0f, 0.0f); }
	void pitch(float angle) { rotate(angle, 1.0f, 0.0f, 0.0f); }
	void roll(float angle) { rotate(angle, 0.0f, 0.0f, 1.0f); }
};