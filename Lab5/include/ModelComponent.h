/**
@file ModelComponent.cpp
*/
#pragma once
#include "Model.h"
#include "Component.h"


class ModelComponent : public Component
{
private:
	Model * theModel;  //!< Creates a pointer to a model

public:
	ModelComponent(Model *model) : theModel(model)
	{

	}

	void OnUpdate(float dt) override
	{

	}

	void OnMessage(const std::string s)
	{

	}

	Model* getModel()
	{
		return theModel;	//!< Returns a model when called
	}
};