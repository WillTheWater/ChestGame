#include "Playing.h"

Playing::Playing()
{
}

void Playing::HandleInput(const sf::Event& event)
{
}

void Playing::Update()
{
    // Game logic updates (e.g., chest, items)
}

void Playing::Draw(sf::RenderWindow& window) 
{
    window.clear(); // Example use of this-> (optional)
    // Draw the game world, items, etc.
    window.display();
}