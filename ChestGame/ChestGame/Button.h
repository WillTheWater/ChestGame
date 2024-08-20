#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
class Button
{
public:
	Button();
	~Button();
	void DrawButton(sf::RenderWindow& gameWindow);
	bool StartGame(sf::RenderWindow& gameWindow);
	void ButtonText(const std::string& text, const unsigned int size);
private:
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;
	sf::Text buttonText;
	sf::Font diabloFont;
	
	
};

