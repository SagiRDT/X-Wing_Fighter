#include "SpaceshipEnemyAdvanced.h"
#include "Controller.h"

//SpaceshipEnemyAdvanced builder
SpaceshipEnemyAdvanced::SpaceshipEnemyAdvanced(sf::Vector2f position, sf::Sprite& sprite)
	:SpaceshipEnemy(position, sprite, ENEMY_ADV_RANGE)
{
	initAnimationFrames();
	m_hp = ENEMY_ADV_HP;
	m_pointWorth = ENEMY_ADV_POINTS;
}

//SpaceshipEnemyAdvanced builder
SpaceshipEnemyAdvanced::SpaceshipEnemyAdvanced(sf::Vector2f position, std::string path)
	: SpaceshipEnemy(position, path, ENEMY_ADV_RANGE)
{
	initAnimationFrames();
	m_hp = ENEMY_ADV_HP;
	m_pointWorth = ENEMY_ADV_POINTS;
}

//SpaceshipEnemyAdvanced destructor
SpaceshipEnemyAdvanced::~SpaceshipEnemyAdvanced()
{
}

//initializing all the sprite animation frames
void SpaceshipEnemyAdvanced::initAnimationFrames()
{
	//set the animations
	m_animationTiltLeft.addFrame(sf::IntRect(0, 0, 99, 59));
	m_animationTiltLeft.addFrame(sf::IntRect(0, 60, 99, 59));
	m_animationTiltLeft.addFrame(sf::IntRect(0, 120, 99, 59));

	m_animationRegular.addFrame(sf::IntRect(100, 0, 99, 59));
	m_animationRegular.addFrame(sf::IntRect(100, 60, 99, 59));
	m_animationRegular.addFrame(sf::IntRect(100, 120, 99, 59));

	m_animationTiltRight.addFrame(sf::IntRect(200, 0, 99, 59));
	m_animationTiltRight.addFrame(sf::IntRect(200, 60, 99, 59));
	m_animationTiltRight.addFrame(sf::IntRect(200, 120, 99, 59));

	m_animationTiltLeft.setSpriteSheet(m_texture);
	m_animationRegular.setSpriteSheet(m_texture);
	m_animationTiltRight.setSpriteSheet(m_texture);
}

//Calculating the next enemy move
//First the ship will get in fire range, than it will chase the player or move randomaly (50%-50%)
//Output: MoveDirection that tells the next move of the ship, NONE for shoting
MoveDirection SpaceshipEnemyAdvanced::calculateMove(Controller& controller)
{
	int rand;
	//check the player location
	sf::Vector2f playerPos = controller.getPlayerPos();

	//if the player ship is in the line of fire shot it - return NONE as the direction
	if ((playerPos.y - m_animatedSprite.getPosition().y <= m_range) &&
		((playerPos.x - 20) <= m_animatedSprite.getPosition().x && (playerPos.x + 20) >= m_animatedSprite.getPosition().x))
	{
		//_RPT1(0, "player x=%f, player y=%f, enemy x=%f, enemy y=%f\n", playerPos.x, playerPos.y, m_animatedSprite.getPosition().x, m_animatedSprite.getPosition().y);
		return NONE;
	}
	//else get in the line of fire (the simple enemy moves randomaly)
	else
	{
		//get a random number 0 or 1 - if its 0 seek the player, else move randomaly
		srand((unsigned)time(NULL));
		rand = std::rand() % 2;

		//if rand is 0 lock on to the target
		if (rand == 0)
		{
			//first get in range
			if (playerPos.y - m_animatedSprite.getPosition().y > m_range)
				return DOWN;
			//seek the target and shoot
			if (playerPos.x + 10 > m_animatedSprite.getPosition().x)
				return RIGHT;
			else
				return LEFT;
		}
		//else move randomaly
		else {
			//get a random number and move according to the result
			srand((unsigned)time(NULL));
			rand = std::rand() % 4;

			switch (rand)
			{
			case 0:
				return DOWN;
				break;
			case 1:
				return UP;
				break;
			case 2:
				return LEFT;
				break;;
			case 3:
				return RIGHT;
				break;
			default:
				break;
			}
		}
	}
	return DOWN;
}
