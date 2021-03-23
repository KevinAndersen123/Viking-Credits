#include "Player.h"

Viking::Viking() : m_pos{10.0f, 400.0f}
{
	loadTextures();
	m_viking.setPosition(m_pos);
	m_viking.setScale(0.8, 0.8);
	m_viking.setOrigin(50, 50);
}

Viking::~Viking()
{
}

void Viking::loadTextures()
{
	if (!m_texture_viking.loadFromFile("ASSETS/IMAGES/sit.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
	
	if (!m_textureWalk.loadFromFile("ASSETS/IMAGES/walking.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
	m_viking.setTexture(m_texture_viking);

}


sf::Sprite Viking::getSprite() const
{
	return  m_viking;
}

void Viking::moveRight()
{
	m_pos.x += m_speed;
	m_viking.setPosition(m_pos);
	walkAnimation();
}

void Viking::rotate()
{
	
	if (m_timer >= 0 && m_timer < 120)
	{
		m_timer++;
	}
	else if (m_timer >= 120)
	{
		m_viking.rotate(-2);
		m_timer = 0;
	}
	if (m_timer == 30)
	{
		m_viking.rotate(-2);
	}
	if (m_timer == 60)
	{
		m_viking.rotate(2);
	}
	if (m_timer == 90)
	{
		m_viking.rotate(2);
	}
	m_pos.y += -(float)std::cos(m_pos.x / 15);

	m_viking.setPosition(sf::Vector2f(0.0f, 30.0f) + m_pos);
}

void Viking::setPos(sf::Vector2f t_pos)
{
	m_pos = t_pos;
	m_viking.setPosition(sf::Vector2f(0.0f,30.0f)+t_pos);
}

void Viking::walkAnimation()
{
	if (m_animationTimer >= 0 && m_animationTimer < 150)
	{
		m_animationTimer++;
	}
	else if (m_animationTimer >= 150)
	{
		m_viking.setTextureRect(sf::IntRect(475, 1, 95, 134));
		m_animationTimer = 0;
	}
	if (m_animationTimer == 0)
	{
		m_viking.setTextureRect(sf::IntRect(1, 1, 95, 134));
	}
	if (m_animationTimer == 30)
	{
		m_viking.setTextureRect(sf::IntRect(95, 1, 95, 134));
	}
	if (m_animationTimer == 60)
	{
		m_viking.setTextureRect(sf::IntRect(190, 1, 95, 134));
	}
	if (m_animationTimer == 90)
	{
		m_viking.setTextureRect(sf::IntRect(285, 1, 95, 134));
	}
	if (m_animationTimer == 120)
	{
		m_viking.setTextureRect(sf::IntRect(380, 1, 95, 134));
	}
}

void Viking::changeTexture()
{
	m_viking.setTexture(m_textureWalk);
	m_viking.setPosition(m_pos + sf::Vector2f(0.0f, 50.0f));
}





