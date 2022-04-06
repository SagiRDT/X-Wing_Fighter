#include "PowerUpAmmo.h"
#include "SpaceshipPlayer.h"

//PowerUpAmmo builder
PowerUpAmmo::PowerUpAmmo(int randX, sf::Texture& texture, int ammo)
	:PowerUp(sf::Vector2f(float(1000.0 + randX), -10.0F), texture), m_ammo(ammo)//create that object a little out of the screen
{
	initAnimationFrames();
	play();
}

//PowerUpAmmo destructor
PowerUpAmmo::~PowerUpAmmo()
{
}

//PowerUpAmmo collide with spaceship - gives the ship more missiles
//return true if it collides with the player, flase if isnt
bool PowerUpAmmo::collide(Spaceship* spcship, Controller & controller)
{
	if (SpaceshipPlayer *p = dynamic_cast<SpaceshipPlayer*>(spcship))
	{
		p->addAmmo(m_ammo);
		m_animatedSprite.setPosition(-1000.0, -1000.0); //"destroy" the powerup - world clean function will delete it
		return true;
	}
	return false;
}
