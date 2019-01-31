/**
@file Game.cpp
*/
#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>
#include <string>

Game::Game()
{
	m_engineInterfacePtr = nullptr;   //! Sets the engine interface pointer to null
	//m_inputHandler = new InputHandler(m_currentScene->getControlledObject());
	
	//m_playerBackground = new GameObject();
	//
	//m_playerBackground.addComponent(new RedComponent);
	//m_playerBackground.addComponent(new GreenComponent);
	//m_playerBackground.addComponent(new BlueComponent);

	modelManager = new ModelManager();  //! Creates the model manager class


	// Load the scene
	m_currentScene = new Scene();  //! Creates the scene class

	//m_currentScene->loadLevel("assets/Levels/myCubeLevel.txt");

	m_currentScene->loadLevelJSON("assets/Levels/myCubeLevel1.json", modelManager);  //! Loads the json level file

	m_inputHandler = new InputHandler(m_currentScene->getControlledObject());    //! Lets the user control the player model

}

void Game::update()
{
	// Hallo
}

void Game::render()
{
	float redValue = 0, greenValue = 0, blueValue = 0.5f;
	//if(m_playerBackground.getComponent<RedComponent>())
	//	redValue = m_playerBackground.getComponent<RedComponent>()->m_colourValue;
	//if (m_playerBackground.getComponent<GreenComponent>())
	//	greenValue = m_playerBackground.getComponent<GreenComponent>()->m_colourValue;
	//if (m_playerBackground.getComponent<BlueComponent>())
	//	blueValue = m_playerBackground.getComponent<BlueComponent>()->m_colourValue;
	
	// e.g. pass object details to the engine to render the next frame
	m_engineInterfacePtr->renderColouredBackground(redValue, greenValue, blueValue);   //! Sets the colour of the background

	// update the camera (probably don't need to do this each frame)
	m_engineInterfacePtr->setCamera(m_currentScene->getControlledObject()->getComponent<CameraComponent>());   //! Sets the camera's position to the player model's position
		
		//&m_camera);

	// draw the cube
	//m_engineInterfacePtr->drawCube(m_playerCube.getComponent<TransformComponent>()->getModelMatrix());
	//m_engineInterfacePtr->drawCube(m_playerCube2.getComponent<TransformComponent>()->getModelMatrix());

	m_currentScene->render(m_engineInterfacePtr);  //! Draws the currently loaded scene to the screen
	
}



