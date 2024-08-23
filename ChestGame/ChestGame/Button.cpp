#include <iostream>
#include "Button.h"

Button::Button(const std::string& textString, const std::string& texturePath)
	: m_ButtonText{ textString, m_ButtonFont }

{
	m_ButtonTexture.loadFromFile(texturePath);
	m_ButtonFont.loadFromFile("assets/font/bolddiablo.ttf");
	m_ButtonText.setFont(m_ButtonFont);
	m_ButtonText.setFillColor(sf::Color::Black);
	SetFontSize(36);
	m_ButtonSprite.setColor(m_DefaultColor);
	m_ButtonSprite.setTexture(m_ButtonTexture);
	IsButtonDown = false;
	CenterText();
}

sf::FloatRect Button::GetBounds() const
{
    return m_ButtonSprite.getGlobalBounds();
}

void Button::SetButtonText(const std::string& buttonText)
{
    m_ButtonText.setString(buttonText);
	CenterText();
}

void Button::SetFontSize(unsigned int fontSize)
{
    m_ButtonText.setCharacterSize(fontSize);
	CenterText();
}

bool Button::HandleEvent(const sf::Event& event)
{
	bool handled = false;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_ButtonSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				std::cout << "Button Clicked\n";
				IsButtonDown = true;
				OnButtonDown();
			}
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (IsButtonDown && m_ButtonSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				std::cout << "Button Released\n";
				OnButtonDown();
				handled = true;
			}
			IsButtonDown = false;
		}
	}
	else if (event.type == sf::Event::MouseMoved)
	{
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (m_ButtonSprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
			{
				OnButtonHover();
			}
			else
			{
				OnButtonUp();
			}
		}
	}
	return handled;
}

void Button::Draw(sf::RenderWindow& gamewindow)
{
	CenterText();
	gamewindow.draw(m_ButtonSprite);
	gamewindow.draw(m_ButtonText);
}

void Button::UpdatePosition(const sf::Vector2f& position)
{
	m_ButtonSprite.setPosition(position);
	m_ButtonText.setPosition(position);
}

void Button::CenterText()
{
	sf::FloatRect bound = GetBounds();
	sf::Vector2f center = sf::Vector2f{ bound.left + bound.width / 2.f, bound.top + bound.height / 2.f };
	sf::FloatRect textBound = m_ButtonText.getGlobalBounds();
	m_ButtonText.setPosition(center - sf::Vector2f{ textBound.width / 2.f, textBound.height });
}

void Button::OnButtonUp()
{
	IsButtonDown = false;
	m_ButtonSprite.setColor(m_DefaultColor);
}

void Button::OnButtonDown()
{
	IsButtonDown = true;
	m_ButtonSprite.setColor(m_DownColor);
}

void Button::OnButtonHover()
{
	m_ButtonSprite.setColor(m_HoverColor);
}

