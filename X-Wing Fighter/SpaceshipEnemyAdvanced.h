#pragma once
#include "SpaceshipEnemy.h"

#define ENEMY_ADV_HP 50
#define ENEMY_ADV_RANGE 800
#define ENEMY_ADV_POINTS 200

class SpaceshipEnemyAdvanced :
	public SpaceshipEnemy
{
public:
	SpaceshipEnemyAdvanced(sf::Vector2f position, sf::Sprite& sprite);
	SpaceshipEnemyAdvanced(sf::Vector2f position, std::string path);
	virtual ~SpaceshipEnemyAdvanced();

	MoveDirection calculateMove(Controller& controller);
	void initAnimationFrames();
};

