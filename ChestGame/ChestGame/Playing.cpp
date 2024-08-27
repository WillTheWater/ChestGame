#include "Playing.h"

Playing::Playing()
{
	mPlayingBackgroundTexture.loadFromFile("assets/graphics/background.png");
	mPlayingBackgroundSprite.setTexture(mPlayingBackgroundTexture);
}

Playing::~Playing()
{
	std::cout << "Playing deleted" << std::endl;
}

void Playing::Update(sf::RenderWindow& window)
{
	//std::cout << "Playing is Being Updated" << std::endl;
}

void Playing::Draw(sf::RenderWindow& window)
{
	window.draw(mPlayingBackgroundSprite);
	mResetButton.InitButton("Reset", "assets/graphics/button.png", window, sf::Vector2f{ window.getSize().x - mResetButton.GetBounds().width,window.getSize().y - mResetButton.GetBounds().height });
	mQuitButton.InitButton("Exit the Kurast", "assets/graphics/button.png", window, sf::Vector2f{ 0, window.getSize().y - mQuitButton.GetBounds().height });
	mChest.SpawnChest(window);
	
}

bool Playing::HandleEvent(sf::Event event)
{
	return false;
}

int Playing::HandleButtonEvent(sf::Event event)
{
	if (mResetButton.HandleEvent(event))
	{
		std::cout << "Reset Level\n";
		return 1;
	}
	if (mQuitButton.HandleEvent(event))
	{
		std::cout << "Quit\n";
		return 2;
	}
	return 0;
}
