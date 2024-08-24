#pragma once
#include "GameState.h"


class GameStateManager {
public:
    void SetState(std::unique_ptr<GameState> newState);
    void HandleInput(const sf::Event& event);
    void Update();
    void Draw(sf::RenderWindow& window);

private:
    std::unique_ptr<GameState> m_CurrentState;
};