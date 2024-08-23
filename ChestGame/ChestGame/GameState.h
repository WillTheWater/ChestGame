#pragma once
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState() = default;

    virtual void HandleInput(sf::RenderWindow& window) = 0;
    virtual void Update() = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};