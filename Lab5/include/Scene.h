/**
@file Scene.h
*/
#pragma once
#include "Model.h"
#include "ModelComponent.h"
#include <iostream>
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "CameraComponent.h"
#include "json/json.h"
#include "ModelManager.h"


class Scene
{
public:
	Scene();  //!< Scene class constructor
	void loadLevel(std::string levelFile);	//!< Loads a .txt file level
	void render(IEngineCore* m_engineInterfacePtr);	//!< Renders models to the screen
	bool loadLevelJSON(std::string levelJSONFile, ModelManager* modelManager);  //!< Loads a json file level
	PlayerCharacter* getControlledObject();  //!< Pointer to the model that is being controlled by the player
	

private:

	std::vector<GameObject*> v_GameObjects;  //!< Holds a vector of game objects   

	//std::vector<ModelManager> v_models;

};