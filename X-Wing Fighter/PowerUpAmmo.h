#pragma once
#include "PowerUp.h"

class PowerUpAmmo :
	public PowerUp
{
public:
	PowerUpAmmo(int randX, sf::Texture& texture, int ammo);
	virtual ~PowerUpAmmo();

	virtual bool collide(Spaceship* spcship, Controller& controller);

	int giveAmmo() { return m_ammo; }

private:
	int m_ammo;
};

