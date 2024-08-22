#include "Item.h"

Item::Item(const std::string& name,  float dropProbabilty, bool isStackable, int quantity)
	:m_Name{name},
	m_DropProbability{dropProbabilty},
	m_IsStackabe{isStackable},
	m_Quantity{quantity}
{
	m_Sprite.setTexture(m_Texture);
	m_Font.loadFromFile("assets/font/lightdiablo.ttf");
	m_DisplayName.setFont(m_Font);
	m_DisplayName.setCharacterSize(25);
	m_DisplayName.setFillColor(sf::Color::White);
}

Item::~Item()
{
}

const std::string& Item::GetName() const
{
	return m_Name;
}

const sf::Sprite& Item::GetSprite() const
{
	return m_Sprite;
}

float Item::GetDropProbability() const
{
	return m_DropProbability;
}

bool Item::IsStackable() const
{
	return m_IsStackabe;
}

int Item::GetQuantity() const
{
	return m_Quantity;
}

const sf::Text& Item::GetDisplayName() const
{
	return m_DisplayName;
}

void Item::SetQuantity(int quantity)
{
	if (m_IsStackabe) { m_Quantity = quantity; }
}

void Item::AddtoStack(int amount)
{
	if(m_IsStackabe) { m_Quantity += amount; }
}

void Item::SubtractFromStack(int amount)
{
	if (m_IsStackabe)
	{ 
		m_Quantity -= amount;
		if (m_Quantity < 0) { m_Quantity = 0; }
	}
}

void Item::DrawItem(sf::RenderWindow& window, const sf::Vector2f& position)
{
	m_Sprite.setPosition(position);
	window.draw(m_Sprite);
	sf::FloatRect spriteBounds    = m_Sprite.getGlobalBounds();
	sf::FloatRect textBounds      = m_DisplayName.getGlobalBounds();
	float textX                   = position.x + (spriteBounds.width / 2.f) - (textBounds.width / 2.f);
	float textY                   = position.y - spriteBounds.height;
	m_DisplayName.setPosition(textX, textY);
	sf::RectangleShape textBackground;
	textBackground.setSize(sf::Vector2f(textBounds.width + 10.f, textBounds.height + 4.f));
	textBackground.setFillColor(sf::Color(0, 0, 0, 150));
	textBackground.setPosition(textX - 5.f, textY - 2.f);
	window.draw(textBackground);
	window.draw(m_DisplayName);
}

void Item::SetDisplayNameColor(const sf::Color& color)
{
	m_DisplayName.setFillColor(color);
}

void Item::SetPosition(float x, float y)
{
	m_Sprite.setPosition(x, y);
}
