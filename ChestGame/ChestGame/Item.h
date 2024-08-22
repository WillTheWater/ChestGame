#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Item
{
public:
	Item(const std::string& name, float dropProbabilty, bool isStackable = true, int quantity = 1);
	virtual ~Item();

	// Getter functions
	const std::string& GetName() const;
	const sf::Sprite& GetSprite() const;
	float GetDropProbability() const;
	bool IsStackable() const;
	int GetQuantity() const;
	const sf::Text& GetDisplayName() const;

	// Setter functions
	void SetQuantity(int quantity);
	void AddtoStack(int amount);
	void SubtractFromStack(int amount);
	void DrawItem(sf::RenderWindow& window, const sf::Vector2f& position);
	void SetDisplayNameColor(const sf::Color& color);

protected:
	std::string m_Name;
	sf::Sprite m_Sprite;
	sf::Text m_DisplayName;
	sf::Texture m_Texture;
	sf::Font m_Font;
	float m_DropProbability;
	bool m_IsStackabe;
	int m_Quantity;

};

