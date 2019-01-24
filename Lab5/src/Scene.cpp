/**
@file Scene.cpp
*/
#include <Scene.h>
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Model.h"


Scene::Scene()  //! Scene constructor
{
	
}

void Scene::loadLevel(std::string levelFile)
{
	int numCubesRead;
	std::stringstream ss;
	std::string s;
	std::ifstream inputFile;

	float x, y, z, w;

	inputFile.open(levelFile);

	if (inputFile.is_open())
	{
		
		std::getline(inputFile, s); //! read the first line which has the number of elements
		ss.str(s);
		ss.ignore(17); //! ignore the first 17 chars
		ss >> numCubesRead;

		v_GameObjects.resize(numCubesRead);  //! Resize the vector
		ss.clear();

		for (int i = 0; i < numCubesRead; i++)
		{		
			getline(inputFile, s); //! Ignore first line
			ss.clear();
			
			getline(inputFile, s); //! read in position
			ss.clear();
			ss.str(s);
			ss >> x >> y >> z;
			glm::vec3 pos(x, y, z);
			
			getline(inputFile, s); //! read in orientation
			ss.clear();
			ss.str(s);
			ss >> x >> y >> z >> w;
			glm::quat orient(x, y, z, w);
		
			getline(inputFile, s); //! read in scale
			ss.clear();
			ss.str(s);
			ss >> x >> y >> z;
			glm::vec3 scale(x, y, z);

			//v_GameObjects[i].addComponent(new TransformComponent(pos, orient, scale));
		}
	}
}

void Scene::render(IEngineCore* m_engineInterfacePtr)
{
	for (int i = 0; i < v_GameObjects.size(); i++)
	{
		//m_engineInterfacePtr->drawCube(v_playerCubes[i].getComponent<TransformComponent>()->getModelMatrix());
	
		Model *model = v_GameObjects[i]->getComponent<ModelComponent>()->getModel();  //! Gets thge model component of the model about to be drawn
		glm::mat4 modelMatrix =	v_GameObjects[i]->getComponent<TransformComponent>()->getModelMatrix();  //! Gets thge transform component of the model matrix about to be drawn
	
		m_engineInterfacePtr->drawModel(model, modelMatrix);  //! Draws all the game objects
	
	}
}

bool Scene::loadLevelJSON(std::string levelJSONFile, ModelManager* modelManager)
{
	std::fstream jsonData;
	Json::Value root;
	Json::Reader reader;

	jsonData.open(levelJSONFile.c_str());    //! Opens the json file
	//Model *myTestModel = new Model("assets/Models/sphereModel.obj");
	//v_models.getModel("assets/Models/sphereModel.obj");
	
	
	
	if (!reader.parse(jsonData, root))  //! Check for errors
	{
		std::cout << "Failed to parse data from: "
				  << levelJSONFile
				  << reader.getFormattedErrorMessages();
		return false;
	}

	const Json::Value gameObjects = root["GameObjects"];

	//v_GameObjects.resize(gameObjects.size());

	// size() tells us how large the array is
	for (int i = 0; i < gameObjects.size(); i++)
	{
		 
		std::cout << gameObjects[i]["name"].asString() << " loaded\n"; //! Get string

		std::string modelName = gameObjects[i]["modelName"].asString(); //! Get the model name

		Model* thisModel = modelManager->getModel(modelName); //! Get the model from the model manager

		float x, y, z;
		
		const Json::Value posNode = gameObjects[i]["position"]; //! Get the position node
		x = posNode[0].asFloat(); //! Get float
		y = posNode[1].asFloat();
		z = posNode[2].asFloat();
		glm::vec3 pos(x, y, z);

		if (i == 0)
		{
			PlayerCharacter* pc = new PlayerCharacter(thisModel, pos); //! Create player

			v_GameObjects.push_back(pc);

		}
		else
		{
			GameObject* go = new GameObject(thisModel, pos); //! Other models

			v_GameObjects.push_back(go);
		}

	}
	return true;
}

PlayerCharacter * Scene::getControlledObject()
{
	return (PlayerCharacter*) v_GameObjects[0]; //! The first model loaded becomes the controlled object
}
