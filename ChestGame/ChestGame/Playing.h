#pragma once
#include "GameState.h"

class Playing : public GameState 
{
public:
    Playing();
    void HandleInput(const sf::Event& event) override;
    void Update() override;
    void Draw(sf::RenderWindow& window) override;

private:
};