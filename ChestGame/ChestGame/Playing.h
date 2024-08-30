#pragma once
#include "State.h"
#include "Chest.h"
#include "Button.h"

class Playing : public State
{
public:
	Playing();
	~Playing() override;
	void						Update(sf::RenderWindow& window) override;
	void						Draw(sf::RenderWindow& window) override;
	bool						HandleEvent(sf::Event event) override;
	int							HandleButtonEvent(sf::Event event) override;

private:
	sf::Texture					mPlayingBackgroundTexture;
	sf::Sprite					mPlayingBackgroundSprite;
	Chest*						mChest;
	Button						mResetButton;
	Button						mQuitButton;
};

