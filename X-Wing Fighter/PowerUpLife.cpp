#include "PowerUpLife.h"
#include "SpaceshipPlayer.h"

//PowerUpLife builder
PowerUpLife::PowerUpLife(int randX, sf::Texture & texture, int lives)
	:PowerUp(sf::Vector2f(float(1000.0 + randX), -10.0F), texture), m_lives(lives)
{
	initAnimationFrames();
	play();
}

//PowerUpLife destructor
PowerUpLife::~PowerUpLife()
{
}

//PowerUpLife collide with space ship - gives the player life
//return true if it collides with the player, flase if isnt
bool PowerUpLife::collide(Spaceship* spcship, Controller & controller)
{
	if (SpaceshipPlayer *p = dynamic_cast<SpaceshipPlayer*>(spcship))
	{
		p->addLife(m_lives);
		m_animatedSprite.setPosition(-1000.0, -1000.0);//"destroy" the powerup - world clean function will delete it
		return true;
	}
	return false;
}
