#pragma once
#include "Weapon.h"

class Controller;

class WeaponHomingMissile :
	public Weapon
{
public:
	WeaponHomingMissile(sf::Vector2f position, sf::Sprite & sprite, sf::Sound& sound, bool targetIsPlayer);
	WeaponHomingMissile(sf::Vector2f position, sf::Texture& texture, sf::Sound& sound, bool targetIsPlayer, sf::Vector2f enemyPos);
	virtual ~WeaponHomingMissile();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void move(MoveDirection direction, Controller& controller) override;
	virtual void initAnimationFrames() override;
private:
	sf::Vector2f calculateFlyDirection(Controller& controller);

	bool m_targetIsPlayer;
};

