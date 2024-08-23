#include "GameStateManager.h"

void GameStateManager::SetState(std::unique_ptr<GameState> newState) {
    this->m_CurrentState = std::move(newState);
}

void GameStateManager::HandleInput(sf::RenderWindow& window) {
    if (this->m_CurrentState) {
        this->m_CurrentState->HandleInput(window);
    }
}

void GameStateManager::Update() {
    if (this->m_CurrentState) {
        this->m_CurrentState->Update();
    }
}

void GameStateManager::Draw(sf::RenderWindow& window) {
    if (this->m_CurrentState) {
        this->m_CurrentState->Draw(window);
    }
}