#pragma once
#include "PowerUp.h"

class PowerUpDelay :
	public PowerUp
{
public:
	PowerUpDelay(int randX, sf::Texture& texture, float delayMultiplier);
	virtual ~PowerUpDelay();

	float getDelay() { return m_delayMultiplier; }

	virtual bool collide(Spaceship* spcship, Controller& controller);

private:
	float m_delayMultiplier;
};

