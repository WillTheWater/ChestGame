#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class State
{
public:
	virtual ~State(){}
	virtual void				Update(sf::RenderWindow& window) = 0; 
	virtual void				Draw(sf::RenderWindow& window) = 0;
	virtual bool				HandleEvent(sf::Event event) = 0;
	virtual int					HandleButtonEvent(sf::Event event) = 0;
};