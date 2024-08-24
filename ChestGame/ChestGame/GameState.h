#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState() = default;

    virtual void HandleInput(const sf::Event& event) = 0;
    virtual void Update() = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};