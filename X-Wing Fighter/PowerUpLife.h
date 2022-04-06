#pragma once
#include "PowerUp.h"

class PowerUpLife :
	public PowerUp
{
public:
	PowerUpLife(int randX, sf::Texture& texture, int lives);
	virtual ~PowerUpLife();

	virtual bool collide(Spaceship* spcship, Controller& controller);

	int addLifes() { return m_lives; }

private:

	int m_lives;
};

