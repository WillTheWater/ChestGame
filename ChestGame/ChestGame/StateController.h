#pragma once
#include "State.h"
#include "MainMenu.h"
#include "Playing.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class StateController
{
public:
	~StateController();
	void					InitState();
	void					SwitchState(State* newState);
	void					StateUpdate(sf::RenderWindow& window);
	void					StateDraw(sf::RenderWindow& window);
	int						StateEvent(sf::Event event);

private:
	State*					currentState = nullptr;
};

