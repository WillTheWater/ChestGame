#pragma once
#include "SFML/Graphics.hpp"
class Button
{
public:
	Button();
	~Button();
	void DrawButton(sf::RenderWindow& gameWindow);
	bool StartGame(sf::RenderWindow& gameWindow);
private:
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;
};

