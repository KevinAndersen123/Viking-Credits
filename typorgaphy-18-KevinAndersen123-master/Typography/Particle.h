#pragma once
#pragma once
#pragma once
// Author Rbo
// Particle.h
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
class Particle
{
public:
	int timetoLive;
	sf::Vector2f velocity;
	sf::RectangleShape shape;

	void Draw(sf::RenderWindow& win)
	{
		if (timetoLive>0)
		{
			win.draw(shape);
		}
	}
	void Update()
	{
		if (timetoLive>0)
		{
			shape.move(velocity);

			timetoLive--;
		}
	}
	void Particle::setColour()
	{
		shape.setFillColor(sf::Color(128, 9, 9));
	}
	Particle() {}

	Particle(sf::Vector2f pos, sf::Vector2f vel)
	{
		shape.setSize(sf::Vector2f(rand() % 4 + 1, rand() % 4 + 1));
		shape.setPosition(pos);
		velocity = vel;
		timetoLive = rand() % 150;
		if (timetoLive < 50)
		{
			shape.setFillColor(sf::Color(242, 125, 12));
		}
		else if (timetoLive > 50 && timetoLive < 65)
		{
			shape.setFillColor(sf::Color(240, 127, 19));		//(255, 156, 50)
		}
		else
			shape.setFillColor(sf::Color(253, 207, 88));
	}

};

