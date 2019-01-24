/**
@file Game.h
*/
#pragma once
#include "Scene.h"
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "CameraComponent.h"
#include "ModelManager.h"
#include <iostream>


class Game
{
public:
	Game();		//!< Constructor for the game class
	IEngineCore* m_engineInterfacePtr;	//!< Object pointer to the IEngineCore class

	InputHandler* m_inputHandler;	//!< Object pointer to the InputHandler class

	PlayerCharacter* getControlledObject();   //!< Object pointer to the PlayerCharacter class

	Scene* m_currentScene;		//!< Object pointer to the Scene class

	ModelManager* modelManager;		//!< Object pointer to the the ModelManager class

	void update();		//!< Update function 
	void render();		//!< Renders all models to the screen

	//void loadLevel(std::string levelFile);

private:
	//GameObject m_playerBackground;


	//std::vector<GameObject> v_playerCubes;

	//CameraComponent m_cameraComponent;
};
