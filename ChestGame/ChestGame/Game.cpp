#include <iostream>
#include "SFML/Graphics.hpp"
#include "Chest.h"
#include "Button.h"
#include "GameStates.h"

Button startButton;


int main()
{
    // Game window
    sf::RenderWindow gameWindow(sf::VideoMode(1920, 1080), "The Lower Kurast");
    sf::Image windowIcon;
    windowIcon.loadFromFile("assets/graphics/icon.png");
    gameWindow.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());
    //-----------------------------------------------------------------------------------------------------------
    // Cursor
    sf::Cursor cursorOpen;
    sf::Image cursorOpenImage;
    cursorOpenImage.loadFromFile("assets/graphics/cursoropen.png");
    cursorOpen.loadFromPixels(cursorOpenImage.getPixelsPtr(), cursorOpenImage.getSize(), { 0, 0 });
    gameWindow.setMouseCursor(cursorOpen);
    sf::Cursor cursorClosed;
    sf::Image cursorClosedImage;
    cursorClosedImage.loadFromFile("assets/graphics/cursorclosed.png");
    cursorClosed.loadFromPixels(cursorClosedImage.getPixelsPtr(), cursorClosedImage.getSize(), { 0, 0 });

    gameWindow.setFramerateLimit(60);
    sf::Clock clock;
    //-----------------------------------------------------------------------------------------------------------
    // Background Texture
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/graphics/background.png"); 
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    
    // Main game loop
    while (gameWindow.isOpen())
    {
        // Calculate deltaTime (time since last frame)
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();
        // Mouse Postion
        sf::Vector2f mousePos = gameWindow.mapPixelToCoords(sf::Mouse::getPosition(gameWindow));
        //-----------------------------------------------------------------------------------------------------------
        // Process events
        
        
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { gameWindow.close(); }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){ gameWindow.setMouseCursor(cursorClosed); }
        else { gameWindow.setMouseCursor(cursorOpen); }
        switch (gameState)
        {
            case GameState::MainMenu:
                if (startButton.StartGame(gameWindow)) { gameState = GameState::Playing; }
                break;
            case GameState::Playing:
                //TODO
                break;
        }
        // Render GameStates
        gameWindow.clear();
        switch (gameState) 
        {
            case GameState::MainMenu:
               
                startButton.DrawButton(gameWindow); 
                break;
            case GameState::Playing:
                gameWindow.draw(backgroundSprite);
                break;
        }
        gameWindow.display();
    }
    return 0;
}