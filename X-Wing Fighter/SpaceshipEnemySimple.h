#pragma once
#include "SpaceshipEnemy.h"

#define ENEMY_SMPL_HP 25
#define ENEMY_SMPL_RANGE 300
#define ENEMY_SMPL_POINTS 100

class SpaceshipEnemySimple :
	public SpaceshipEnemy
{
public:
	SpaceshipEnemySimple(sf::Vector2f position, sf::Sprite& sprite);
	SpaceshipEnemySimple(sf::Vector2f position, std::string path);
	virtual ~SpaceshipEnemySimple();

	MoveDirection calculateMove(Controller& controller);
	void initAnimationFrames();
};

