#include "Weapon.h"
#include "SpaceshipEnemySimple.h"
#include "Spaceship.h"

Weapon::Weapon(sf::Vector2f position, sf::Sprite & sprite, float power)
	:GameObj(position, sprite),m_power(power)
{
}

Weapon::Weapon(sf::Vector2f position, sf::Texture & texture, float power)
	: GameObj(position, texture), m_power(power)
{
}

bool Weapon::collide(Spaceship* ship, Controller& controller)
{
	//_RPT1(0, "Collide Weapon with Spaceship!!\n", 0);
	ship->takeDamage((int)m_power);
	if (ship->getHp() <= 0)
		ship->explode(controller);
	return true;
}

bool Weapon::collide(Weapon* weapon, Controller& controller)
{
	//_RPT1(0, "Collide Weapon with Weapon!!\n", 0);
	return true;
}

bool Weapon::collide(GameObj* obj, Controller& controller)
{
	//_RPT1(0, "Collide Weapon with GameObj!!\n", 0);//
	return obj->collide(this, controller);
}

Weapon::~Weapon()
{
}
