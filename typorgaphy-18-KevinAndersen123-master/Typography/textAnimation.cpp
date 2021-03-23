#include "textAnimation.h"

textAnimation::textAnimation()
{
	loadTextures();
	initialise();
	m_logo.setTexture(m_texture);
	m_logo.setScale(0.09, 0.09);
}

textAnimation::~textAnimation()
{
}

void textAnimation::loadTextures()
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/sfml.png"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}
}

sf::Sprite textAnimation::getSprite() const
{
	return m_logo;
}

void textAnimation::update(sf::Time dt)
{
	
	acceleration = gravity;
	sf::Vector2f unitVector;
	unitVector.x = velocity.x / sqrt(velocity.x*velocity.x + velocity.y*velocity.y);
	unitVector.y = velocity.y / sqrt(velocity.x*velocity.x + velocity.y*velocity.y);
	
	position = position + velocity * dt.asSeconds() + (0.5f * acceleration * (dt.asSeconds() * dt.asSeconds()));
	velocity = velocity + acceleration * dt.asSeconds();

	if (position.y + m_logo.getGlobalBounds().height/2 > 350)
	{
		velocity.y = -restitution * velocity.y;
		position.y = 350 - m_logo.getGlobalBounds().height/2;

		if (abs(velocity.y) < 0.5f *pixelsToMeters)
		{
			velocity = sf::Vector2f(0.0f, 0.0f);
		}
	}
	m_logo.setPosition(position);

	if (m_timer >= 0 && m_timer < 50)
	{
		m_timer++;
	}
	else if (m_timer >= 50)
	{
		m_logo.setColor(sf::Color{ 0,0,0,255 });
	}
	if (m_timer == 10)
	{
		
		m_logo.setColor(sf::Color{ 0,0,0,25 });
	}
	if (m_timer == 20)
	{
		
		m_logo.setColor(sf::Color{ 0,0,0,100 });
	}
	if (m_timer == 30)
	{
		
		m_logo.setColor(sf::Color{ 0,0,0,150});
	}

	if (m_timer == 40)
	{
	
		m_logo.setColor(sf::Color{ 0,0,0,200 });
	}
	
	if (m_logo.getRotation() < 359)
	{
		m_logo.rotate(0.5);
	}

}
void textAnimation::initialise()
{
	velocity = sf::Vector2f(100.0f, -1150.0f);
	position = sf::Vector2f(800.0f, 400.0f);
	m_logo.setPosition(position);
	m_logo.setColor(sf::Color{ 0,0,0,20});
	m_logo.rotate(180);
}





