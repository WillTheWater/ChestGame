#include <iostream>
#include "SFML/Graphics.hpp"
#include "Chest.h"


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


    // Background Texture
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/graphics/background.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    //-----------------------------------------------------------------------------------------------------------

    // Chest Texture
   // sf::Texture chestTexture;
    //chestTexture.loadFromFile("assets/graphics/chest.png");
    //sf::Sprite chestSprite;
   // chestSprite.setTexture(chestTexture);
    Chest chest1;
    Chest chest2;
    Chest chest3;
    //chestSprite.setPosition(chest1.SetRandomPosition());
    //chestSprite.setTextureRect(sf::IntRect(0, 0, 50, 60));
    //bool canOpenChest = true;
    //-----------------------------------------------------------------------------------------------------------

    // Set the frame rate limit
    gameWindow.setFramerateLimit(60);
    sf::Clock clock;
    //-----------------------------------------------------------------------------------------------------------

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
            if (event.type == sf::Event::Closed)
                gameWindow.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                gameWindow.setMouseCursor(cursorClosed);
                /*if (chestSprite.getGlobalBounds().contains(mousePos))
                {
                    if (canOpenChest)
                    {
                        chestSprite.setTextureRect(sf::IntRect(50, 0, 50, 60));
                        std::cout << "Chest is Opened!" << std::endl;
                        canOpenChest = false;
                    }
                    else{ std::cout << "Chest is already Open!" << std::endl; }
                }*/
            }
            else { gameWindow.setMouseCursor(cursorOpen); }
        }
        //----------------------------------------------------------

        // Update game logic here (e.g., move objects, handle input)

        //----------------------------------------------------------

        // Clear the screen
        gameWindow.clear(sf::Color::Black);

        //----------------------------------------------------------

        // Draw your game objects here
        // For example: window.draw(someSprite);
        gameWindow.draw(backgroundSprite);
        chest1.SpawnChest(gameWindow);
        chest2.SpawnChest(gameWindow);
        chest3.SpawnChest(gameWindow);

        //----------------------------------------------------------
        // Display what has been drawn to the screen
        gameWindow.display();
    }
	return 0;
}