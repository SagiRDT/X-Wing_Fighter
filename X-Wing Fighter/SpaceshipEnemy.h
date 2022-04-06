#pragma once
#include "Spaceship.h"

class Controller;

class SpaceshipEnemy :
	public Spaceship
{
public:
	SpaceshipEnemy(sf::Vector2f position, sf::Sprite& sprite, int range);
	SpaceshipEnemy(sf::Vector2f position, std::string path, int range);
	virtual ~SpaceshipEnemy();

	void move(MoveDirection direction, Controller& controller);
	virtual MoveDirection calculateMove(Controller& controller) = 0;
	virtual void explode(Controller& controller);

	int getWorthPoints() { return m_pointWorth; }

protected:
	int m_range;
	int m_pointWorth;
};

