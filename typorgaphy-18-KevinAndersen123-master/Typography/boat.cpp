#include "boat.h"



Boat::Boat(): m_pos { 250.0f, 450.0f }
{
	loadTextures();
	m_boat.setPosition(m_pos);
	m_boat.setScale(0.8, 0.8);
	m_boat.setOrigin(512 / 2, 512 / 2);
}

Boat::~Boat()
{
}
void Boat::loadTextures()
{
	if (!m_texture_boat.loadFromFile("ASSETS/IMAGES/boat.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
	m_boat.setTexture(m_texture_boat);
}
sf::Sprite Boat::getSprite() const
{
	return m_boat;
}

void Boat::moveRight()
{
	
	m_pos.x += m_speed;

	m_boat.setPosition(m_pos);
}

void Boat::rotate()
{
	
	m_pos.y += -(float)std::cos(m_pos.x/17);

	m_boat.setPosition(m_pos);	
}

sf::Vector2f Boat::getPosition()
{
	return m_pos;
}
