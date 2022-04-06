#include "SpaceshipPlayer.h"
#include "Controller.h"
#include "PowerUpAmmo.h"
#include "PowerUpLife.h"
#include "PowerUpDelay.h"

SpaceshipPlayer::SpaceshipPlayer(sf::Vector2f position, sf::Sprite& sprite, int lives)
	:Spaceship(position, sprite), m_lives(lives)
{
	//set the score on 0
	m_score = 0;
	//hp
	m_hp = MAX_HP;
	initAnimationFrames();
	m_shootDir = 1;
}

SpaceshipPlayer::SpaceshipPlayer(sf::Vector2f position, std::string path, int lives)
	:Spaceship(position, path), m_lives(lives)
{
	//set the score on 0  
	m_score = 0;
	//hp
	m_hp = MAX_HP;
	initAnimationFrames();
	m_shootDir = 1;
	m_ammo[MISSILE] = 1;
	m_delayLimit[MISSILE] = 2000;
}

SpaceshipPlayer::~SpaceshipPlayer()
{
}

//spaceship collision with an PowerUp

//exploding the ship - if it has lives left it will be reborn! and if not it will be removed from the universe
void SpaceshipPlayer::explode(Controller& controller)
{
	//get the player location
	sf::Vector2f pos = m_animatedSprite.getPosition();

	//lower the player lives
	m_lives--;

	//if he have no lives its game over
	if (m_lives == 0)
	{
		//add the ship to the to be destroyed vector
		controller.addToBeDestroyedShip(pos);
		//tell the controller that theres is an explosion that should happan at the spaceship location
		controller.getWorld()->addToBeCreatedExplosion(pos);
		//the player is dead, GAME OVER
		dead(controller);
	}
	//else he will be respawned with full hp
	else
	{
		//add the ship to the to be destroyed vector
		controller.addToBeDestroyedShip(pos);
		//tell the controller that theres is an explosion that should happan at the spaceship location
		controller.getWorld()->addToBeCreatedExplosion(pos);
		//respawn the player
		m_animatedSprite.setPosition(sf::Vector2f(850.0, 900.0));
		m_hp = MAX_HP;
	}
}

//if the SpaceshipPlayer exploded and have no spare lives then its game over
void SpaceshipPlayer::dead(Controller& controller)
{
	m_isDead = true;
	//put it utside of the game world and makes all its ammo 0 so it wont be able to shot and make sounds
	m_animatedSprite.setPosition(sf::Vector2f(-1000.0, -1000.0));
	for (size_t i = 0; i < m_ammo.size(); i++) {
		m_ammo[i] = 0;
	}
	controller.gameOver();
}
//set the animation frames
void SpaceshipPlayer::initAnimationFrames()
{
	//left
	m_animationTiltLeft.addFrame(sf::IntRect(0, 0, 99, 59));
	m_animationTiltLeft.addFrame(sf::IntRect(0, 60, 99, 59));
	m_animationTiltLeft.addFrame(sf::IntRect(0, 120, 99, 59));
	//straight
	m_animationRegular.addFrame(sf::IntRect(100, 0, 99, 59));
	m_animationRegular.addFrame(sf::IntRect(100, 60, 99, 59));
	m_animationRegular.addFrame(sf::IntRect(100, 120, 99, 59));
	//right
	m_animationTiltRight.addFrame(sf::IntRect(200, 0, 99, 59));
	m_animationTiltRight.addFrame(sf::IntRect(200, 60, 99, 59));
	m_animationTiltRight.addFrame(sf::IntRect(200, 120, 99, 59));

	m_animationTiltLeft.setSpriteSheet(m_texture);
	m_animationRegular.setSpriteSheet(m_texture);
	m_animationTiltRight.setSpriteSheet(m_texture);
}
//this function moves the player spaceship
void SpaceshipPlayer::move(MoveDirection direction, Controller& controller)
{
	sf::Vector2f newPos;

	//if it moved left or right tilt it
	switch (direction)
	{
		case UP:
		{
			newPos = sf::Vector2f(0, -SPACESHIP_SPEED);
			break;
		}
		case DOWN:
		{
			newPos = sf::Vector2f(0, SPACESHIP_SPEED);
			break;
		}
		case LEFT:
		{
			newPos = sf::Vector2f(-SPACESHIP_SPEED, 0);
			break;
		}
		case RIGHT:
		{
			newPos = sf::Vector2f(SPACESHIP_SPEED, 0);
			break;
		}
	}
	//_RPT1(0, "new pos: %f, %f\n", newPos.x, newPos.y);
	
	//if it moved left or right tilt it
	setAnimation(direction);

	//if the newPos is not inside the game bounds then dont move!
	sf::Vector2f newShipPos = m_animatedSprite.getPosition() + newPos;
	if ( newShipPos.x > SCREEN_X - 100 ||
		 newShipPos.x < 20 ||
		 newShipPos.y > SCREEN_Y - 150 ||
		 newShipPos.y < 100)
		newPos = sf::Vector2f(0, 0);

	//move the ship to the new position
	m_animatedSprite.move(newPos);
	
}
//collision with ammo pack
bool SpaceshipPlayer::collide(PowerUpAmmo* pwup, Controller& controller)
{
	addAmmo(pwup->giveAmmo());
	return false;
}
//collision with life pack
bool SpaceshipPlayer::collide(PowerUpLife* pwup, Controller& controller)
{

	addLife(pwup->addLifes());
	return false;
}
//collision with delay decrease pack
bool SpaceshipPlayer::collide(PowerUpDelay* pwup, Controller& controller)
{
	mulDelay(pwup->getDelay());
	return false;
}
//adds ammo to all cartriges
void SpaceshipPlayer::addAmmo(int ammo)
{
	for (unsigned i = 1; i < m_ammo.size(); ++i) //no need to give ammo to laser
		m_ammo[i] += ammo;
}
//adds life to spaceship and refills hp
void SpaceshipPlayer::addLife(int lifes)
{
	if (m_lives < 3)
		m_lives += lifes;
	m_hp = MAX_HP;
}
//decreases the delay of all weapons
void SpaceshipPlayer::mulDelay(float multiplier)
{
	for (unsigned i = 0; i < m_delayLimit.size(); ++i)
		if(m_delayLimit[i] > 400)
			m_delayLimit[i] *= multiplier;
}
