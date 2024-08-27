#pragma once
#include <sstream>
#include <iostream>
#include "StateController.h"
#include <SFML/Graphics.hpp>


class Game
{
public:
	Game();
	void					Run();

private:
	void					ProcessEvents();
	void					Update(sf::Time elapsedTime);
	void					UpdateGameState();
	void					Render();

	void					UpdateStatistics(sf::Time elapsedTime);
	void					HandleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
	void					HandleMouseInput(sf::Mouse::Button button, bool isPressed);

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
	sf::Image				mWindowIcon;
	StateController			mStateController;
};