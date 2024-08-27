#include "Game.h"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
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

	// Window icon
	mWindowIcon.loadFromFile("assets/graphics/icon.png");
	mWindow.setIcon(mWindowIcon.getSize().x, mWindowIcon.getSize().y, mWindowIcon.getPixelsPtr());

	mFont.loadFromFile("assets/font/bolddiablo.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(40);

	// State Controller
	mStateController.InitState();
}

void Game::Run()
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

			ProcessEvents();
			Update(TimePerFrame);
		}

		UpdateStatistics(elapsedTime);
		UpdateGameState();
		Render();
	}
	mStateController.~StateController(); // Delete the State Controller
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::MouseButtonPressed:
				HandleMouseInput(event.mouseButton.button, true); //mWindow.setMouseCursor(mCursorClosed); std::cout << "Mouse Close\n";
				break;

			case sf::Event::MouseButtonReleased:
				HandleMouseInput(event.mouseButton.button, false); //mWindow.setMouseCursor(mCursorOpen); std::cout << "Mouse Open\n";
				break;

			case sf::Event::KeyPressed:
				HandleKeyboardInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				HandleKeyboardInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
		switch(mStateController.StateEvent(event))
		{
			case 1:
				mStateController.SwitchState(new Playing);
				break;

			case 2:
				mWindow.close();
				exit(0);
				break;

		}
		// State event handling
		
		
		
		// Only for testing state machine
		//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			//;
		//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
			//mStateController.SwitchState(new MainMenu);
	}		  
}			  
			  
void Game::Update(sf::Time elapsedTime)
{			  
	// Mouse update
	if (mMouseClick) { mWindow.setMouseCursor(mCursorClosed); }
	else { mWindow.setMouseCursor(mCursorOpen); }
			  
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

}

void Game::UpdateGameState()
{
	//mStateController.StateUpdate(mWindow);
}

void Game::Render()
{
	mWindow.clear();
	mWindow.draw(mStatisticsText);
	mStateController.StateDraw(mWindow);
	mWindow.display();
}

void Game::UpdateStatistics(sf::Time elapsedTime)
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

void Game::HandleKeyboardInput(sf::Keyboard::Key key, bool isPressed)
{
	
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void Game::HandleMouseInput(sf::Mouse::Button button, bool isPressed)
{
	if (button == sf::Mouse::Left)
		mMouseClick = isPressed;
}
