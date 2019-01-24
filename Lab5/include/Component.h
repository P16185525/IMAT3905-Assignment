/**
@file Component.h
*/
#pragma once

#include <string>

class Component
{
public:
	virtual void OnUpdate(float dt) = 0;
	virtual void OnMessage(const std::string m) = 0;  //!< Uses a string to deal with different key presses

};

