/**
@file GameObject.h
*/
#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "ModelComponent.h"
#include <unordered_map>
#include <typeindex>

class GameObject : public Component
{
public:

	GameObject(Model* model, glm::vec3 position)
	{
		addComponent(new TransformComponent(position));  //!< Adds a transform component to the the game object
		addComponent(new ModelComponent(model));		 //!< Adds a model component to the game object
	};


	template <typename T>
	T* getComponent()		
	{

		auto iter = m_components.find(typeid(T));

		if(iter != std::end(m_components))
		{
			
			return dynamic_cast<T*>(iter->second);  //!< if found dynamic cast the component pointer and return it
		}
		
		
		return nullptr; //!< return null if we don't have a component of that type
		
	}

	template <typename T>
	void addComponent(T* comp)
	{
		
		m_components[typeid(T)] = comp; //!< add the component to unordered map with hash of its typeid
	}
	

	void OnUpdate(float dt) override
	{

	}
	void OnMessage(const std::string m) override
	{

	}

protected:
	std::unordered_map<std::type_index, Component*> m_components;
};

class PlayerCharacter : public GameObject
{
public:


	// redo constructor to add model, transform and camera
	PlayerCharacter(Model* model, glm::vec3 position) : GameObject( model, position )
	{
		addComponent(new TransformComponent(position));		//!< Adds a transform component to the the player character
		addComponent(new ModelComponent(model));			//!< Adds a model component to the the player character
		addComponent(new CameraComponent(position));		//!< Adds a camera component to the the player character
	};


	void OnMessage(const std::string m) override
	{
		TransformComponent* tc = getComponent<TransformComponent>();  //!< Gets the transform component of the player character

		tc->OnMessage(m);

		// copy tc position and orientration to the camera - camera moves with you....

		glm::vec3 pos = tc->m_position;
		glm::quat orient = tc->m_orientation;

		pos += glm::vec3(0, 2, 7) * orient;


		CameraComponent* cc = getComponent<CameraComponent>();

		cc->m_position = pos;  //!< Copies the tc position and orientation to the camera so that in moves with the player character

	}


};
