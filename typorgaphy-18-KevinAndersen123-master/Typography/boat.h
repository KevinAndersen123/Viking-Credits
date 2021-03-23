#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Boat
{
private:
	sf::Texture m_texture_boat; //texture for viking
	sf::Sprite m_boat; // sprite used for viking

	void loadTextures();
	int m_timer{ 0 };
	sf::Vector2f m_pos{};
	double m_speed{ 1.0 };
	
public:
	Boat();
	~Boat();
	sf::Sprite getSprite() const;
	void moveRight();
	void rotate();
	sf::Vector2f getPosition();
};