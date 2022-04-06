#include "SpaceshipEnemySimple.h"
#include "Controller.h"

//SpaceshipEnemySimple builder
SpaceshipEnemySimple::SpaceshipEnemySimple(sf::Vector2f position, sf::Sprite& sprite)
	:SpaceshipEnemy(position, sprite, ENEMY_SMPL_RANGE)
{
	initAnimationFrames();
	m_hp = ENEMY_SMPL_HP;
	m_pointWorth = ENEMY_SMPL_POINTS;
}

//SpaceshipEnemySimple builder
SpaceshipEnemySimple::SpaceshipEnemySimple(sf::Vector2f position, std::string path)
	: SpaceshipEnemy(position, path, ENEMY_SMPL_RANGE)
{
	initAnimationFrames();
	m_hp = ENEMY_SMPL_HP;
	m_pointWorth = ENEMY_SMPL_POINTS;
}

//SpaceshipEnemySimple destructor
SpaceshipEnemySimple::~SpaceshipEnemySimple()
{
}

//initializing all the sprite animation frames
void SpaceshipEnemySimple::initAnimationFrames()
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
//The ssimple ship will move randomaly
//Output: MoveDirection that tells the next move of the ship, NONE for shoting
MoveDirection SpaceshipEnemySimple::calculateMove(Controller& controller)
{
	int rand;
	//get the player location
	sf::Vector2f playerPos = controller.getPlayerPos();

	//_RPT1(0, "player x=%f, player y=%f, enemy x=%f, enemy y=%f\n", playerPos.x, playerPos.y, m_animatedSprite.getPosition().x, m_animatedSprite.getPosition().y);

	//if the player ship is in the line of fire shot it - return NONE as the direction
	if ( (playerPos.y - m_animatedSprite.getPosition().y <= m_range) &&
		 ( (playerPos.x - 100.0) <= m_animatedSprite.getPosition().x && (playerPos.x + 100.0) >= m_animatedSprite.getPosition().x) )
	{
		return NONE;
	}
	//else get in the line of fire (the simple enemy moves randomaly)
	else
	{
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
	return NONE;
}

