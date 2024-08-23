#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu()
    :m_StartButton("Start Game"), m_QuitButton("Exit the Kurast")
{
    m_MainmenuTexture.loadFromFile("assets/graphics/mainmenu.png");
    m_MainmenuSprite.setTexture(m_MainmenuTexture);
    std::cout << "Main Menu loaded\n";
}

void MainMenu::HandleInput(sf::RenderWindow& window) 
{
    // Handle input for the main menu
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                std::cout << "mouse pressed\n";
            }
        }
        // Forward the event to the button
        m_StartButton.HandleEvent(event);
    }
        std::cout << "Event tick\n";
}

void MainMenu::Update() {
    // Update logic for the main menu
}

void MainMenu::Draw(sf::RenderWindow& window) 
{
    // Set button positions
    m_StartButton.UpdatePosition(sf::Vector2f{ window.getSize().x / 2.f - m_StartButton.GetBounds().width / 2.f,window.getSize().y / 2.f });
    m_QuitButton.UpdatePosition(sf::Vector2f{ window.getSize().x / 2.f - m_QuitButton.GetBounds().width / 2.f,window.getSize().y / 2.f + m_StartButton.GetBounds().height });

    window.clear(); // Example use of this-> (optional)

    // Draw main menu items
    window.draw(m_MainmenuSprite);
    m_StartButton.Draw(window);
    m_QuitButton.Draw(window);
    window.display();
}