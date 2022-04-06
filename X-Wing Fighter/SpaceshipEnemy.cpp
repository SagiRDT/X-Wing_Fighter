#include "SpaceshipEnemy.h"
#include "Controller.h"

//SpaceshipEnemy builder
SpaceshipEnemy::SpaceshipEnemy(sf::Vector2f position, sf::Sprite& sprite, int range)
	:Spaceship(position, sprite), m_range(range)
{
	m_shootDir = -1;
}

//SpaceshipEnemy builder
SpaceshipEnemy::SpaceshipEnemy(sf::Vector2f position, std::string path, int range)
	: Spaceship(position, path), m_range(range)
{
	m_shootDir = -1;
}

//SpaceshipEnemy destructor
SpaceshipEnemy::~SpaceshipEnemy()
{
}

//exploding the ship and removing from the universe
void SpaceshipEnemy::explode(Controller& controller)
{
	//play explosion animation
	sf::Vector2f pos = m_animatedSprite.getPosition();
	//add the ship to the to be destroyed vector
	controller.addToBeDestroyedShip(pos);
	//tell the controller that theres is an explosion that should happan at the spaceship location
	controller.getWorld()->addToBeCreatedExplosion(pos);
}

//Make the enemy take a move
//First the enemy will calculate his next move and then he will excute it
//The function also check that the mov hes trying to make is in screen bounds
void SpaceshipEnemy::move(MoveDirection direction, Controller& controller)
{
	sf::Vector2f newPos;
	direction = calculateMove(controller);

	switch (direction)
	{
		//if the direction is NONE - shot!
	case NONE:
		this->shoot(ENEMY_SIMPLE, LASER, controller);
		break;
		//move DOWN
	case DOWN:
		newPos = sf::Vector2f(0, SPACESHIP_SPEED);
		break;
		//move RIGHT
	case RIGHT:
		newPos = sf::Vector2f(SPACESHIP_SPEED, 0);
		break;
		//move LEFT
	case LEFT:
		newPos = sf::Vector2f(-SPACESHIP_SPEED, 0);
		break;
	default:
		break;
	}

	//if the new pos is outside the enemies area than dont move
	if (m_animatedSprite.getPosition().y + newPos.y >= 800 ||		//lower bound
		m_animatedSprite.getPosition().x + newPos.x >= 1800 ||		//right bound
		m_animatedSprite.getPosition().x + newPos.x <= 20 ||		//left bound
		m_animatedSprite.getPosition().y + newPos.y <= 100)			//upper bound
		newPos = sf::Vector2f(0, 0);

	//_RPT1(0, "new pos: %f, %f\n", newPos.x, newPos.y);

	//if it moved left or right tilt it
	setAnimation(direction);
	//move the ship to the new position
	m_animatedSprite.move(newPos);
}