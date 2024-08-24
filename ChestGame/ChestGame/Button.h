#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
class Button
{
public:
	Button(const std::string& textString = "button",
		const std::string& texturePath = "assets/graphics/button.png");
	sf::FloatRect GetBounds() const;
	void SetButtonText(const std::string& buttonText);
	void SetFontSize(unsigned int fontSize);
	bool HandleEvent(const sf::Event& event);
	void Draw(sf::RenderWindow& gamewindow);
	void UpdatePosition(const sf::Vector2f& position);
	void CenterText();
	bool WasClicked();
	
private:
	sf::Texture m_ButtonTexture;
	sf::Sprite m_ButtonSprite;
	sf::Font m_ButtonFont;
	sf::Text m_ButtonText;
	sf::Color m_DefaultColor = sf::Color{ 255, 255, 255, 255 };
	sf::Color m_DownColor = sf::Color{ 100, 100, 100, 255 };
	sf::Color m_HoverColor = sf::Color{ 200, 200, 200, 255 };
	bool IsButtonDown;
	void OnButtonUp();
	void OnButtonDown();
	void OnButtonHover();
};

