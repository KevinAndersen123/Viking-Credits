#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Viking
{
private:
	sf::Texture m_texture_viking; //texture for viking
	sf::Sprite m_viking; // sprite used for viking
	sf::Texture m_textureWalk; //texture for walking
	int m_timer{ 0 };
	void loadTextures();
	double m_speed{ 0.5 };
	int m_animationTimer{ 0 };
public:
	sf::Vector2f m_pos{};
	Viking();
	~Viking();
	sf::Sprite getSprite() const;
	void moveRight();
	void rotate();
	void setPos(sf::Vector2f t_pos);
	void walkAnimation();
	void changeTexture();

};

