#include <iostream>
#include "SFML/Graphics.hpp"
#include "Chest.h"
#include "Button.h"
#include "GameStates.h"




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
    sf::Texture mainmenuTexture;
    mainmenuTexture.loadFromFile("assets/graphics/mainmenu.png");
    sf::Sprite mainmenuSprite;
    mainmenuSprite.setTexture(mainmenuTexture);
    //-----------------------------------------------------------------------------------------------------------
    // Start Button
    Button startButton;
    startButton.UpdatePosition(sf::Vector2f{ gameWindow.getSize().x/2.f - startButton.GetBounds().width/2.f,gameWindow.getSize().y / 2.f});
    startButton.SetButtonText("Start Game");
    Button quitButton;
    quitButton.UpdatePosition(sf::Vector2f{ gameWindow.getSize().x / 2.f - quitButton.GetBounds().width / 2.f,gameWindow.getSize().y / 2.f + startButton.GetBounds().height});
    quitButton.SetButtonText("Quit Game");
    Button resetButton;
    resetButton.UpdatePosition(sf::Vector2f{ gameWindow.getSize().x / 2.f - resetButton.GetBounds().width / 2.f,gameWindow.getSize().y - resetButton.GetBounds().height });
    resetButton.SetButtonText("Reset");
    //-----------------------------------------------------------------------------------------------------------
    // Chests
    Chest chest1;
    Chest chest2;
    Chest chest3;

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
                if (startButton.HandleEvent(event)) { gameState = GameState::Playing; }
                if (quitButton.HandleEvent(event)) { gameWindow.close(); }
                break;
            case GameState::Playing:
                if (resetButton.HandleEvent(event)) { gameState = GameState::MainMenu; }
                break;
        }
        // Render GameStates
        gameWindow.clear();
        switch (gameState) 
        {
            case GameState::MainMenu:
                gameWindow.draw(mainmenuSprite);
                startButton.Draw(gameWindow); 
                quitButton.Draw(gameWindow);
                break;
            case GameState::Playing:
                gameWindow.draw(backgroundSprite);
                chest1.SpawnChest(gameWindow);
                chest2.SpawnChest(gameWindow);
                chest3.SpawnChest(gameWindow);
                resetButton.Draw(gameWindow);
                break;
        }
        gameWindow.display();
    }
    return 0;
}