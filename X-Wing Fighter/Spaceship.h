#pragma once
#include "GameObj.h"
#include "WeaponLaser.h"
#include "WeaponHomingMissile.h"
#include"Explosion.h"

class GameObj;
class Weapon;
class PowerUp;
class Obstacle;

enum WeaponNum {LASER, MISSILE, BOMB, MINE, BOSS_SUPER_STRIKE};
enum Spaceships {PLAYER, ENEMY_SIMPLE, ENEMY_ADV, BOSS};
float const SHIPS_LENGTH[4] = { 100, -100, -100, -100 };
float const SHIPS_WIDTH[4] = { 80, 80, 80, 80 };
#define SPACESHIP_SPEED 8

class Controller;

class Spaceship :
	public GameObj
{
public:
	Spaceship();//
	Spaceship(sf::Vector2f position, sf::Sprite& sprite);
	Spaceship(sf::Vector2f position, std::string& path);
	virtual ~Spaceship();

	virtual bool collide(GameObj* obj, Controller& controller);
	virtual bool collide(Spaceship* ship, Controller& controller);
	virtual bool collide(Weapon* weapon, Controller& controller);
	
	virtual void explode(Controller& controller) = 0;

	virtual void draw(sf::RenderWindow& window);
	void setAnimation(MoveDirection position);

	void shoot(Spaceships ship, WeaponNum weapon, Controller& controller);

	int getShootDir() { return m_shootDir; }

	void takeDamage(int damage);

	int getHp() { return m_hp; }

	std::vector<int> getAmmo() { return m_ammo; }

protected:

	int m_hp;
	std::vector<int> m_ammo;					//array that holds the ammo of each wep, accessible via using the enum of the weps
	std::vector<sf::Clock> m_afterShoot;		//indicates how much time elapsed since last shot for each weapon
	std::vector<sf::Int64> m_delayLimit;		//array that indicates each weapon's delay(time before the weapon can shoot)
	Animation m_animationTiltLeft;
	Animation m_animationTiltRight;

	int m_shootDir;

};

