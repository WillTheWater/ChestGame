#include "MainMenu.h"


MainMenu::MainMenu()
{
	mMainmenuBackgroundTexture.loadFromFile("assets/graphics/mainmenu.png");
	mMainmenuBackgroundSprite.setTexture(mMainmenuBackgroundTexture);
	
}

MainMenu::~MainMenu()
{
	std::cout << "MainMenu deleted" << std::endl;
}

void MainMenu::Update(sf::RenderWindow& window)
{
	
}

void MainMenu::Draw(sf::RenderWindow& window)
{
	window.draw(mMainmenuBackgroundSprite);
	mStartButton.InitButton("Start", "assets/graphics/button.png", window, sf::Vector2f {window.getSize().x / 2.f - mStartButton.GetBounds().width/2.f, window.getSize().y / 2.f});
	mQuitButton.InitButton("Exit the Kurast", "assets/graphics/button.png", window, sf::Vector2f {window.getSize().x / 2.f - mStartButton.GetBounds().width/2.f, window.getSize().y / 2.f + mStartButton.GetBounds().height});
}

bool MainMenu::HandleEvent(sf::Event event)
{
	
	return false;
}

int MainMenu::HandleButtonEvent(sf::Event event)
{
	if (mStartButton.HandleEvent(event))
	{
		std::cout << "Play\n";
		std::cout << "Returning 1\n";
		return 1;
	}
	if (mQuitButton.HandleEvent(event))
	{
		std::cout << "Quit\n";
		std::cout << "Returning 2\n";
		return 2;
	}
	return 0;
}

