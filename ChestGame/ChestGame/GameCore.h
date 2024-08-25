#pragma once
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>


class GameCore
{
public:
	GameCore();
	void					run();

private:
	void					processEvents();
	void					update(sf::Time elapsedTime);
	void					render();

	void					updateStatistics(sf::Time elapsedTime);
	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	sf::Texture				mTexture;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;

	std::size_t				mStatisticsNumFrames;
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;
	bool					mMouseClick;

	// Cursor
	sf::Cursor				mCursorOpen;
	sf::Image				mCursorOpenImage;
	sf::Cursor				mCursorClosed;
	sf::Image				mCursorClosedImage;
};