/**
@file ModelManager.h
*/
#pragma once

#include <unordered_map>
#include <typeindex>
#include "Model.h"
#include <map>

class ModelManager
{

private:
	std::map<std::string, Model*> m_models; //!< Creates a map of strings and model pointer

public:
	ModelManager();   //!< Constructor for model manager class
	Model* getModel(std::string filename);		//!< Returns a model if it is in the map
};
