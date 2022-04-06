#pragma once
#include "SpaceshipEnemy.h"

class SpaceshipEnemyBoss :
	public SpaceshipEnemy
{
public:
	SpaceshipEnemyBoss(sf::Vector2f position, sf::Sprite& sprite);
	SpaceshipEnemyBoss(sf::Vector2f position, std::string path);
	virtual ~SpaceshipEnemyBoss();

	virtual void move(MoveDirection direction, Controller& controller);
	MoveDirection calculateMove(Controller& controller) { return NONE; };
};

