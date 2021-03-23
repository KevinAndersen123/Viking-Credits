#pragma once
#pragma once
#pragma once
#pragma once
// Author Dr. Noel O'Hara
// ParticleSystem.h
#include "Particle.h"
#define maxParticles 60
class fire
{
public:

	Particle particles[maxParticles];
	sf::Vector2f position;
	void Initialise(sf::Vector2f pos)
	{
		position = pos;

		for (int i = 0; i<maxParticles; i++)
		{
			if (particles[i].timetoLive <= 0)
				particles[i] = Particle(position, sf::Vector2f(rand() / double(RAND_MAX) * 2 - 1, rand() / double(RAND_MAX) * 1- 2));
		}
	}
	void Update()
	{
		for (int i = 0; i<maxParticles; i++)
		{

			particles[i].Update();
		}
	}
	void Draw(sf::RenderWindow &win)
	{
		for (int i = 0; i<maxParticles; i++)
		{
			particles[i].Draw(win);
		}
	}

	fire() {}
};

