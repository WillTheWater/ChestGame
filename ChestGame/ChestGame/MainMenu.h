#pragma once
#include "Button.h"
#include "GameState.h"

class MainMenu : public GameState
{
public:
    MainMenu();
    void HandleInput(sf::RenderWindow& window) override;
    void Update() override;
    void Draw(sf::RenderWindow& window) override;
private:
    sf::Texture m_MainmenuTexture;
    sf::Sprite m_MainmenuSprite;
    Button m_StartButton;
    Button m_QuitButton;
};