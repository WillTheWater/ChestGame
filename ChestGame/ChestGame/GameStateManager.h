#pragma once

#include "GameState.h"
#include <memory>

class GameStateManager {
public:
    void SetState(std::unique_ptr<GameState> newState);
    void HandleInput(sf::RenderWindow& window);
    void Update();
    void Draw(sf::RenderWindow& window);

private:
    std::unique_ptr<GameState> m_CurrentState;
};