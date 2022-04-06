#pragma once
#include "Weapon.h"

class SpaceshipEnemySimple;
class Spaceship;

class WeaponLaser :
	public Weapon
{
public:
	WeaponLaser(sf::Vector2f position, sf::Sprite& sprite, sf::Sound& sound, int dir);
	WeaponLaser(sf::Vector2f position, sf::Texture& texture, sf::Sound& sound, int dir);
	virtual ~WeaponLaser();

	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(MoveDirection direction, Controller& controller) override;


	virtual void initAnimationFrames() override;

private:


};

