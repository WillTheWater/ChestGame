#include "Item.h"
#include <iostream>

Item::Item(const std::string& name,  float dropProbabilty, bool isStackable, int quantity)
	:m_Name{name},
	m_DropProbability{dropProbabilty},
	m_IsStackabe{isStackable},
	m_Quantity{quantity}
{
	m_Sprite.setTexture(m_Texture);
	m_Font.loadFromFile("assets/font/lightdiablo.ttf");
	m_DisplayName.setFont(m_Font);
	m_DisplayName.setCharacterSize(20);
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
	textBackground.setSize(sf::Vector2f(textBounds.width + 20.f, textBounds.height + 8.f));
	textBackground.setFillColor(sf::Color(0, 0, 0, 170));
	textBackground.setPosition(textX - 10.f, textY + 4.f);
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

bool Item::Pickup(const sf::Event& event)
{
	bool handled = false;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_Sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				IsItemClicked = true;
			}
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (IsItemClicked && m_Sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				OnPickUp();
				handled = true;
			}
			IsItemClicked = false;
		}
	}
	else if (event.type == sf::Event::MouseMoved)
	{
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (m_Sprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
			{
				OnItemHover();
			}
			else
			{
				m_Sprite.setColor(sf::Color{ 255, 255, 255, 255 });
			}
		}
	}
	return handled;
}

void Item::OnPickUp()
{
	std::cout << "Item pickedup" << std::endl;
}

void Item::OnItemClicked()
{
	bool IsItemClicked = true;
}

void Item::OnItemHover()
{
	m_Sprite.setColor(sf::Color{ 200, 200, 200, 255 });
}
