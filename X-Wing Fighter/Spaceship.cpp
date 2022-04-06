#include "Spaceship.h"
#include "Weapon.h"
#include "WeaponLaser.h"
#include "PowerUp.h"
#include "Obstacle.h"
#include "Controller.h"
#include<SFML\System\Time.hpp>
#define NUM_OF_WEAPONS 2	//num of weps

//Spaceship builder
Spaceship::Spaceship()
{
}

//Spaceship builder
Spaceship::Spaceship(sf::Vector2f position, sf::Sprite& sprite)
	:GameObj(position, sprite)
{
	//initializing the ammo array, the laser get -1 (infinity) ammo and the rest get 0 ammo 
	m_ammo.push_back(-1);			//laser
	m_delayLimit.push_back(1000);	//initial delay of laser = 1 sec

	m_ammo.resize(5);
	m_afterShoot.resize(5);
	m_delayLimit.resize(5);
}

//Spaceship builder
Spaceship::Spaceship(sf::Vector2f position, std::string& path)
	:GameObj(position, path)
{
	//initializing the ammo array, the laser get -1 (infinity) ammo and the rest get 0 ammo 
	m_ammo.push_back(-1);			//laser
	m_delayLimit.push_back(1000);	//initial delay of laser = 1 sec

	m_ammo.resize(5);
	m_afterShoot.resize(5);
	m_delayLimit.resize(5);
}

//Spaceship destructor
Spaceship::~Spaceship()
{
}

//Spaceship builder collosion with wep - the ship lose hp and if the hp is 0 or lower destroy it
bool Spaceship::collide(Weapon* weapon, Controller& controller)
{
	m_hp -= (int)weapon->getPower();
	if (m_hp <= 0)
		explode(controller);
	//_RPT1(0, "Collide Spaceship with Weapon!!\n", 0);
	return true;
}

//Spaceship builder collosion with another spaceship - do nothing (so the enemies wont blow themself up)
bool Spaceship::collide(Spaceship* ship, Controller& controller)
{
	//_RPT1(0, "Collide Spaceship with Spaceship!!\n", 0);
	return false;
}

//Call the collide of the game obj on our Spaceship via polymorphism
//because we dont know which obj is gameobject, were using polymorphism to find out
//and call the correct collide function
bool Spaceship::collide(GameObj* obj, Controller& controller)
{
	_RPT1(0, "Collide Spaceship with GameObj!!\n", 0);
	return obj->collide(this, controller);;
}

//Draw the spaceship
void Spaceship::draw(sf::RenderWindow& window)
{
	window.draw(m_animatedSprite);
}

//Change the spaceship animation if it turns left or right
void Spaceship::setAnimation(MoveDirection position)
{
	switch (position)
	{
	case LEFT:
		m_currentAnimation = &m_animationTiltLeft;
		break;
	case RIGHT:
		m_currentAnimation = &m_animationTiltRight;
		break;
	case UP:
		m_currentAnimation = &m_animationRegular;
		break;
	case DOWN:
		m_currentAnimation = &m_animationRegular;
		break;
	default:
		m_currentAnimation = &m_animationRegular;
		break;
	}
	//add compinsation of transition LEFT->RIGHT=FORWARD=RIGHT->LEFT
}

//Make the spaceship shoot a wep
void Spaceship::shoot(Spaceships ship, WeaponNum weapon, Controller& controller)
{
	bool isPlayerShooting = true;
	//_RPT1(0, "ship: %d wep: %d ammo: %d\n", ship, weapon, m_ammo[weapon]);

	//if the current weapon got no ammo then it cant be fired
	if (m_ammo[weapon] == 0)
		return;

	//check if delay has passed
	if (m_afterShoot[weapon].getElapsedTime() < sf::milliseconds(m_delayLimit[weapon]))
		return;
	else
		m_afterShoot[weapon].restart();
	//check who is shooting
	if (dynamic_cast<SpaceshipEnemy*>(this))
		isPlayerShooting = false;

	//create the weapon object at the head of the spaceship, lower the weapon ammo by 1 and transfer the weapon to the world
	switch (weapon)
	{
	case LASER:
		if(isPlayerShooting)
			controller.getWorld()->addWorldObject(std::make_unique<WeaponLaser>(
				m_animatedSprite.getPosition() + sf::Vector2f((SHIPS_WIDTH[ship] / 2), -(SHIPS_LENGTH[ship] / 2 + (35 * m_shootDir))),
				controller.getPlayerLaserTexture(), 
				controller.getPlayerLaserSound(), 
				m_shootDir));
		else
			controller.getWorld()->addWorldObject(std::make_unique<WeaponLaser>(
				m_animatedSprite.getPosition() + sf::Vector2f((SHIPS_WIDTH[ship] / 2), -(SHIPS_LENGTH[ship] / 2 + (10 * m_shootDir))),
				controller.getEnemyLaserTexture(),
				controller.getEnemyLaserSound(),
				m_shootDir));
		break;

	case MISSILE:

		controller.getWorld()->addWorldObject(std::make_unique<WeaponHomingMissile>(
			m_animatedSprite.getPosition() + sf::Vector2f((SHIPS_WIDTH[ship] / 2), -(SHIPS_LENGTH[ship] / 2)), 
			controller.getMissileTexture(), controller.getEnemyLaserSound(), 
			false, 
			controller.getClosestEnemyPosition(m_animatedSprite.getPosition())));//sound is not siutable//
		m_ammo[weapon]--;
		break;

	default:
		break;
	}
}

//Makes the spaceship take damge 
//Input: the dmg that the ship should take
void Spaceship::takeDamage(int damage)
{
	m_hp -= damage;
}
