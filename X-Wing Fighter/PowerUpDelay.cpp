#include "PowerUpDelay.h"
#include "SpaceshipPlayer.h"


PowerUpDelay::PowerUpDelay(int randX, sf::Texture& texture, float delayMultiplier)
	:PowerUp(sf::Vector2f(float(1000.0 + randX), -10.0F), texture), m_delayMultiplier(delayMultiplier)
{
	initAnimationFrames();
	play();
}

//PowerUpDelay destructor
PowerUpDelay::~PowerUpDelay()
{
}

//PowerUpDelay collide with spaceship - gives the player faster fire rate on the lasers
//return true if it collides with the player, flase if isnt
bool PowerUpDelay::collide(Spaceship * spcship, Controller & controller)
{
	if (SpaceshipPlayer *p = dynamic_cast<SpaceshipPlayer*>(spcship))
	{
		p->mulDelay(m_delayMultiplier);
		m_animatedSprite.setPosition(-1000.0, -1000.0);//"destroy" the powerup - world clean function will delete it
		return true;
	}
	return false;
}
