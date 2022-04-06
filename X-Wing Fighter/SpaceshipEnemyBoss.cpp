#include "SpaceshipEnemyBoss.h"


//SpaceshipEnemyBoss builder
SpaceshipEnemyBoss::SpaceshipEnemyBoss(sf::Vector2f position, sf::Sprite& sprite)
	:SpaceshipEnemy(position, sprite, 200)
{
}

//SpaceshipEnemyBoss builder
SpaceshipEnemyBoss::SpaceshipEnemyBoss(sf::Vector2f position, std::string path)
	:SpaceshipEnemy(position, path, 200)
{

}

//SpaceshipEnemyBoss destructor
SpaceshipEnemyBoss::~SpaceshipEnemyBoss()
{
}

//Makes the boss take his move
void SpaceshipEnemyBoss::move(MoveDirection direction, Controller& controller)
{
}