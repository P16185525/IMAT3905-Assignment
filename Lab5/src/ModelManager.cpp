/**
@file ModelManager.cpp
*/
#include "ModelManager.h"
#include <iostream>


ModelManager::ModelManager()  //! Constructor
{
	//t a = 7;
}

Model* ModelManager::getModel(std::string filename)
{
	// todo

	// 1 look in the map if we've got it already
	// if yes then return the model*

	// if not then load in the model and add the model* and name to the map
	// and return the model *


	auto iter = m_models.find(filename);
	if (iter != std::end(m_models))  //! Iterates through the map to see if a particular model is there
	{
		
		return iter->second;  //! if found dynamic cast the model pointer and return it
	}


	Model *myTestModel = new Model(filename); //! load the model in and add to the map


	
	m_models[filename] = myTestModel;  

	

	return myTestModel;  //! return the model
}