#include "GameCore.h"

const float GameCore::PlayerSpeed = 100.f;
const sf::Time GameCore::TimePerFrame = sf::seconds(1.f / 60.f);

GameCore::GameCore()
	: mWindow(sf::VideoMode(1920, 1080), "The Lower Kurast", sf::Style::Close)
	, mTexture()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
	, mMouseClick(false)
{
	mWindow.setFramerateLimit(60);

	// Cursor
	mCursorOpenImage.loadFromFile("assets/graphics/cursoropen.png");
	mCursorOpen.loadFromPixels(mCursorOpenImage.getPixelsPtr(), mCursorOpenImage.getSize(), { 0, 0 });
	mCursorClosedImage.loadFromFile("assets/graphics/cursorclosed.png");
	mCursorClosed.loadFromPixels(mCursorClosedImage.getPixelsPtr(), mCursorClosedImage.getSize(), { 0, 0 });
	mWindow.setMouseCursor(mCursorOpen);

	mFont.loadFromFile("assets/font/bolddiablo.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(40);
}

void GameCore::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void GameCore::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::MouseButtonPressed:
			mWindow.setMouseCursor(mCursorClosed); std::cout << "Mouse Close\n";
			break;

		case sf::Event::MouseButtonReleased:
			mWindow.setMouseCursor(mCursorOpen); std::cout << "Mouse Open\n";
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void GameCore::update(sf::Time elapsedTime)
{

}

void GameCore::render()
{
	mWindow.clear();
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void GameCore::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void GameCore::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
}