#include "WeaponHomingMissile.h"
#include "Controller.h"


WeaponHomingMissile::WeaponHomingMissile(sf::Vector2f position, sf::Sprite& sprite, sf::Sound& sound, bool targetIsPlayer)
	:Weapon(position, sprite, 50), m_targetIsPlayer(targetIsPlayer)
{
	m_speed = sf::Vector2f(0, -20.0);
	initAnimationFrames();
	m_animationRegular.setSpriteSheet(m_texture);
	play();


	//sound.play();

}

WeaponHomingMissile::WeaponHomingMissile(sf::Vector2f position, sf::Texture& texture, sf::Sound& sound, bool targetIsPlayer, sf::Vector2f enemyPos)
	:Weapon(position, texture, 50), m_targetIsPlayer(targetIsPlayer)
{
	initAnimationFrames();
	m_animationRegular.setSpriteSheet(m_texture);
	play();
	//sound.play();
	//set initial rotation, number of accurances

	//if Y coord is near +/- 100 px =>> cheeck x diss and set rotation horizontally
	if (std::abs(position.y - enemyPos.y) < 100)
	{
		if (position.x > enemyPos.x)
		{
			m_animatedSprite.move(-150, 50);
			m_animatedSprite.setRotation(-90);
		}
		else
		{
			m_animatedSprite.move(150, 50);
			m_animatedSprite.setRotation(90);
		}
	}
	else
	{
		//if missile lunched by player who is BELOW the target
		//or
		//if missile lunched by enemy who is BELOW the player

		//player shoots              from below
		if (!targetIsPlayer && position.y < enemyPos.y)
		{
			m_animatedSprite.move(0.0, 250.0);
			m_animatedSprite.setRotation(180);
		}//enemy shoots           from above
		if (targetIsPlayer && position.y > enemyPos.y)
		{
			m_animatedSprite.move(0.0, -200.0);
			//m_animatedSprite.setRotation(180);
		}
		m_animatedSprite.move(0.0, -50.0);
	}
	//this is important who shoots player shoot off the back=>down not to him himself

		//the missile lunched by player(above) to enemy(below)

		//already set by picture

		//the missile lunched by enemy(above to player(below)

		//already set by picture
}

WeaponHomingMissile::~WeaponHomingMissile()
{
}
//draw the missile
void WeaponHomingMissile::draw(sf::RenderWindow& window)
{
	window.draw(m_animatedSprite);
}
//move the missile
void WeaponHomingMissile::move(MoveDirection direction, Controller& controller)
{	
	m_animatedSprite.move(calculateFlyDirection(controller));
}
//set the animation frames
void WeaponHomingMissile::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(16, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(32, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(48, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(64, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(80, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(96, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(112, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(128, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(144, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(160, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(176, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(192, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(208, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(224, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(240, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(256, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(272, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(288, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(304, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(320, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(336, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(352, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(368, 0, 16, 75));
	m_animationRegular.addFrame(sf::IntRect(384, 0, 16, 75));

}
//this function calculates where to move
sf::Vector2f WeaponHomingMissile::calculateFlyDirection(Controller& controller)
{
	float speed = 9.0F;
	float resFactor = 1.77F; // resolution compensation 16:9
	sf::Vector2f myPosition = m_animatedSprite.getPosition();
	//update target position
	sf::Vector2f closestEnemy;
	if (m_targetIsPlayer)
		closestEnemy = controller.getPlayerPos();
	else
		closestEnemy = controller.getClosestEnemyPosition(myPosition);

	//fix the aim to +\- center of a ship
	closestEnemy.x += 50;
	closestEnemy.y += 30;
	//rotation
	float m = (myPosition.y - closestEnemy.y) / (myPosition.x - closestEnemy.x);
	//two cases: I) Missile starts above the target(initial rotation made in costructor)
	if(myPosition.y > closestEnemy.y)
		if(m > 0.000000000001)
			m_animatedSprite.rotate(-2.5);
		else if (m < -0.000000000001)
			m_animatedSprite.rotate(2.5);
	//check where the target locatd corresponding to the location of the missile
	if(closestEnemy.x > myPosition.x)
		if(closestEnemy.y > myPosition.y)
			return sf::Vector2f(speed, speed * resFactor);
		else if (closestEnemy.y == myPosition.y)
			return sf::Vector2f(speed, 0);
		else
			return sf::Vector2f(speed, -speed * resFactor);
	else if (closestEnemy.x == myPosition.x)
		if (closestEnemy.y > myPosition.y)
			return sf::Vector2f(0, speed * resFactor);
		else if (closestEnemy.y == myPosition.y)
			return sf::Vector2f(0, 0);
		else
			return sf::Vector2f(0, -speed * resFactor);
	else
		if (closestEnemy.y > myPosition.y)
			return sf::Vector2f(-speed, speed * resFactor);
		else if (closestEnemy.y == myPosition.y)
			return sf::Vector2f(-speed, 0);
		else
			return sf::Vector2f(-speed, -speed * resFactor);
}
