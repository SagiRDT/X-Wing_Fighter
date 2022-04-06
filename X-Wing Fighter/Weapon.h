#pragma once
#include "GameObj.h"

class SpaceshipEnemySimple;
class Spaceship;

class Weapon :
	public GameObj
{
public:
	Weapon(sf::Vector2f position, sf::Sprite& sprite, float power);
	Weapon(sf::Vector2f position, sf::Texture& texture, float power);


	virtual bool collide(GameObj* obj, Controller& controller);
	virtual bool collide(Spaceship* ship, Controller& controller);
	virtual bool collide(Weapon* weapon, Controller& controller);

	virtual ~Weapon();

	//return the power of the weapon//
	float getPower() { return m_power; }

protected:

	float m_power;
	sf::Vector2f m_speed;
};

