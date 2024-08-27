#include "Button.h"
#include <iostream>

Button::Button(const std::string& textString, const std::string& texturePath)
	: mButtonText{ textString, mButtonFont }

{
	mButtonTexture.loadFromFile(texturePath);
	mButtonFont.loadFromFile("assets/font/bolddiablo.ttf");
	mButtonText.setFont(mButtonFont);
	mButtonText.setFillColor(sf::Color::Black);
	SetFontSize(36);
	mButtonSprite.setColor(mDefaultColor);
	mButtonSprite.setTexture(mButtonTexture);
	IsButtonDown = false;
	CenterText();
}

sf::FloatRect Button::GetBounds() const
{
	return mButtonSprite.getGlobalBounds();
}

void Button::InitButton(const std::string& textString, const std::string& texturePath, sf::RenderWindow& gamewindow, const sf::Vector2f& position)
{
	SetButtonText(textString);
	SetButtonTexture(texturePath);
	Draw(gamewindow);
	UpdatePosition(position);
	
}

void Button::SetButtonText(const std::string& buttonText)
{
	mButtonText.setString(buttonText);
	CenterText();
}

void Button::SetButtonTexture(const std::string& texturePath)
{
	mButtonTexture.loadFromFile(texturePath);
	mButtonSprite.setTexture(mButtonTexture);
}

void Button::SetFontSize(unsigned int fontSize)
{
	mButtonText.setCharacterSize(fontSize);
	CenterText();
}

bool Button::HandleEvent(const sf::Event& event)
{
	bool handled = false;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (mButtonSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
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
			if (IsButtonDown && mButtonSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				std::cout << "Button Released\n";
				OnButtonDown();
				WasClicked();
				handled = true;
			}
			OnButtonUp();
		}
	}
	else if (event.type == sf::Event::MouseMoved)
	{
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (mButtonSprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
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
	gamewindow.draw(mButtonSprite);
	gamewindow.draw(mButtonText);
}

void Button::UpdatePosition(const sf::Vector2f& position)
{
	mButtonSprite.setPosition(position);
	mButtonText.setPosition(position);
}

void Button::CenterText()
{
	sf::FloatRect bound = GetBounds();
	sf::Vector2f center = sf::Vector2f{ bound.left + bound.width / 2.f, bound.top + bound.height / 2.f };
	sf::FloatRect textBound = mButtonText.getGlobalBounds();
	mButtonText.setPosition(center - sf::Vector2f{ textBound.width / 2.f, textBound.height });
}

bool Button::WasClicked()
{
	return true;
}

void Button::OnButtonUp()
{
	IsButtonDown = false;
	mButtonSprite.setColor(mDefaultColor);
}

void Button::OnButtonDown()
{
	IsButtonDown = true;
	mButtonSprite.setColor(mDownColor);
}

void Button::OnButtonHover()
{
	mButtonSprite.setColor(mHoverColor);
}