#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>
class textAnimation
{
private:
	sf::Texture m_texture; //texture for sfml
	sf::Sprite m_logo; // sprite used for sfml

	float restitution = 0.6f;
	float pixelsToMeters = 20;
	const float FRICTION = 0.8f;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	sf::Vector2f position{ 800.0f, 350.0f };					
	sf::Vector2f acceleration = { 0.0f,0.0f }; 
	sf::Vector2f gravity{ 0.0f, 9.81f*pixelsToMeters };			
	sf::Time timeTaken{ sf::seconds(0.0f) };		
	bool hitGround = true;
	sf::Vector2f m_pos{};
	sf::Clock clock;
	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int m_timer{ 0 };
	void initialise();
	void loadTextures();
public:
	
	textAnimation();
	~textAnimation();
	sf::Sprite getSprite() const;
	void update(sf::Time dt);
	

};