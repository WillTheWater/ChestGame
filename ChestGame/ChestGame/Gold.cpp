#include "Gold.h"
#include <sstream>

Gold::Gold()
	: Item{"Gold", 1.f}
{
	m_Texture.loadFromFile("assets/graphics/gold.png");
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>distr(10, 300);
	std::stringstream ss;
	ss << m_Quantity << " " << m_Name;
	m_DisplayName.setString(ss.str());
	m_Quantity = distr(gen);
	UpdateTextureRect();
}

void Gold::UpdateTextureRect()
{
	if (m_Quantity < 100) { m_Sprite.setTextureRect(sf::IntRect(60, 0, 30, 25)); }
	else if (m_Quantity < 200) { m_Sprite.setTextureRect(sf::IntRect(30, 0, 30, 25)); }
	else if (m_Quantity <= 300) { m_Sprite.setTextureRect(sf::IntRect(0, 0, 30, 25)); }
}
