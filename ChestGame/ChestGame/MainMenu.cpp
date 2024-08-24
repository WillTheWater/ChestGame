#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu()
    :m_StartButton("Start Game"), m_QuitButton("Exit the Kurast")
{
    m_MainmenuTexture.loadFromFile("assets/graphics/mainmenu.png");
    m_MainmenuSprite.setTexture(m_MainmenuTexture);
    std::cout << "Main Menu loaded\n";
}

void MainMenu::HandleInput(const sf::Event& event)
{
    // Handle input for the main menu
    m_StartButton.HandleEvent(event);
    m_QuitButton.HandleEvent(event);
    std::cout << "Event tick\n";
}

void MainMenu::Update() 
{
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