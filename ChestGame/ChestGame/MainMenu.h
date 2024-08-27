#pragma once
#include "State.h"
#include "Button.h"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu() override;
	void						Update(sf::RenderWindow& window) override;
	void						Draw(sf::RenderWindow& window) override;
	bool						HandleEvent(sf::Event event) override;
	int							HandleButtonEvent(sf::Event event) override;
private:
	sf::Texture					mMainmenuBackgroundTexture;
	sf::Sprite					mMainmenuBackgroundSprite;
	Button						mStartButton;
	Button						mQuitButton;
};

