/**
@file InputHandler.h
*/
#pragma once
#include <map>
#include "GameObject.h"
#include <vector>
#include "TransformComponent.h"


class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& playerBackground) = 0;
};


//e.g. class RotateLeftCommand : public InputCommand

class XRotateLeft : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("rotateDown");		//!< On message, rotate the player character down
	}
};

class XRotateRight : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("rotateUp");	 //!< On message, rotate the player character
	}
};

class YRotateUp : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("rotateRight"); //!< On message, rotate the player character
	}
};

class YRotateDown : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
			player.OnMessage("rotateLeft"); //!< On message, rotate the player character
	}
	
};

class ZRollLeft : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("rollRight");  //!< On message, rotate the player character
	
	}
};

class ZRollRight : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("rollLeft");	 //!< On message, rotate the player character
	}
};


class XTranslateLeft : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseX");	   //!< On message, translate the player character's position	
	}
};

class XTranslateRight : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseX");	//!< On message, translate the player character's position
	}
};

class YTranslateUp : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseY");	//!< On message, translate the player character's position
	}
};

class YTranslateDown : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseY");	//!< On message, translate the player character's position
	}
};

class ZTranslateLeft : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseZ");		//!< On message, translate the player character's position
	}
};

class ZTranslateRight : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseZ");			//!< On message, translate the player character's position
	}	
};


class XScaleUp : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseXScale");		//!< On message, scale the player character
	}
};

class XScaleDown : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseXScale");		//!< On message, scale the player character
	}
};

class YScaleUp : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseYScale");		//!< On message, scale the player character
	}
};

class YScaleDown : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseYScale");		//!< On message, scale the player character
		
	}
};

class ZScaleUp : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("increaseZScale");		//!< On message, scale the player character
	}
};

class ZScaleDown : public InputCommand
{
public:
	void execute(GameObject& player) override
	{
		player.OnMessage("decreaseZScale");			//!< On message, scale the player character
	}
};

struct InputHandler
{	
	GameObject* m_player;

	std::map<int, InputCommand*> m_controlMapping;

	InputHandler(GameObject* player) : m_player(player)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[(int) 'R'] = new XRotateLeft;  //!< x rotate (pitch)
		m_controlMapping[(int) 'F'] = new XRotateRight; //!< x rotate 

		m_controlMapping[(int) 'T'] = new YRotateUp;   //!< y rotate (yaw)
		m_controlMapping[(int) 'G'] = new YRotateDown; //!< y rotate
		  
		m_controlMapping[(int) 'Y'] = new ZRollLeft;  //!< z rotate (roll)
		m_controlMapping[(int) 'H'] = new ZRollRight; //!< z rotate

		m_controlMapping[(int) 'A'] = new XTranslateLeft;  //!< x translate 
		m_controlMapping[(int) 'D'] = new XTranslateRight; //!<  x translate 

		m_controlMapping[(int) 'E'] = new YTranslateUp;   //!< y translate 
		m_controlMapping[(int) 'Q'] = new YTranslateDown; //!< y translate 

		m_controlMapping[(int) 'W'] = new ZTranslateLeft;  //!< z translate  
		m_controlMapping[(int) 'S'] = new ZTranslateRight; //!< z translate 

		m_controlMapping[(int) 'U'] = new XScaleUp;  //!< x scale 
		m_controlMapping[(int) 'J'] = new XScaleDown; //!< x scale

		m_controlMapping[(int) 'I'] = new YScaleUp;   //!< y scale
		m_controlMapping[(int) 'K'] = new YScaleDown; //!< y scale

		m_controlMapping[(int) 'O'] = new ZScaleUp;  //!< z scale  
		m_controlMapping[(int) 'L'] = new ZScaleDown; //!< z scale
	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for(const auto& mapEntry : m_controlMapping)
		{
			if(keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(*m_player);
			}
		}

	}
};
