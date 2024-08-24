#pragma once
#include "Button.h"
#include "GameState.h"

class MainMenu : public GameState
{
public:
    MainMenu();
    void HandleInput(const sf::Event& event) override;
    void Update() override;
    void Draw(sf::RenderWindow& window) override;
protected:
    sf::Texture m_MainmenuTexture;
    sf::Sprite m_MainmenuSprite;
    Button m_StartButton;
    Button m_QuitButton;
};