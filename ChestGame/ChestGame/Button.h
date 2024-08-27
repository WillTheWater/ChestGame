#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
class Button
{
public:
	Button(const std::string& textString = "button",
		const std::string& texturePath = "assets/graphics/button.png");
	sf::FloatRect GetBounds() const;
	void						InitButton(const std::string& textString, const std::string& texturePath, sf::RenderWindow& gamewindow, const sf::Vector2f& position);
	void						SetButtonText(const std::string& buttonText);
	void						SetButtonTexture(const std::string& texturePath);
	void						SetFontSize(unsigned int fontSize);
	bool						HandleEvent(const sf::Event& event);
	void						Draw(sf::RenderWindow& gamewindow);
	void						UpdatePosition(const sf::Vector2f& position);
	void						CenterText();
	bool						WasClicked();

private:
	sf::Texture					mButtonTexture;
	sf::Sprite					mButtonSprite;
	sf::Font					mButtonFont;
	sf::Text					mButtonText;
	sf::Color					mDefaultColor = sf::Color{ 255, 255, 255, 255 };
	sf::Color					mDownColor = sf::Color{ 100, 100, 100, 255 };
	sf::Color					mHoverColor = sf::Color{ 200, 200, 200, 255 };
	bool						IsButtonDown;
	void						OnButtonUp();
	void						OnButtonDown();
	void						OnButtonHover();
};
