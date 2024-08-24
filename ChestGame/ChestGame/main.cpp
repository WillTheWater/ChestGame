#include "GameStateManager.h"
#include "MainMenu.h"
#include "Playing.h"
#include "GameCore.h"



int main() {


    GameCore game;
    game.run();

    /*
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "The Lower Kurast");
    window.setFramerateLimit(60);
    sf::Image windowIcon;
    windowIcon.loadFromFile("assets/graphics/icon.png");
    window.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

    sf::Cursor cursorOpen;
    sf::Image cursorOpenImage;
    cursorOpenImage.loadFromFile("assets/graphics/cursoropen.png");
    cursorOpen.loadFromPixels(cursorOpenImage.getPixelsPtr(), cursorOpenImage.getSize(), { 0, 0 });
    window.setMouseCursor(cursorOpen);
    sf::Cursor cursorClosed;
    sf::Image cursorClosedImage;
    cursorClosedImage.loadFromFile("assets/graphics/cursorclosed.png");
    cursorClosed.loadFromPixels(cursorClosedImage.getPixelsPtr(), cursorClosedImage.getSize(), { 0, 0 });

    GameStateManager gameStateManager;
    gameStateManager.SetState(std::make_unique<MainMenu>());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { window.setMouseCursor(cursorClosed); }
        else { window.setMouseCursor(cursorOpen); }
        
        
        gameStateManager.HandleInput(event);
        
        gameStateManager.Update();
        
        gameStateManager.Draw(window);
    }*/

    return 0;
}
