#include "PowerUp.h"


//Power Up builder
PowerUp::PowerUp(sf::Vector2f position, sf::Texture& texture)
	:GameObj(position, texture)
{
}

//Power Up destructor
PowerUp::~PowerUp()
{
}

//Draw the power up
void PowerUp::draw(sf::RenderWindow & window)
{
	window.draw(m_animatedSprite);
}

//Move the power up
void PowerUp::move(MoveDirection direction, Controller & controller)
{
	m_animatedSprite.move(0.0, 1.0);//constant "down" direction
}

//initializing all the sprite animation frames
void PowerUp::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 60, 55));
	m_animationRegular.addFrame(sf::IntRect(60, 0, 60, 55));
	m_animationRegular.addFrame(sf::IntRect(120, 0, 60, 55));
	m_animationRegular.addFrame(sf::IntRect(180, 0, 60, 55));
}

//Power Up collide with game obj
bool PowerUp::collide(GameObj * obj, Controller & controller)
{
	return obj->collide(this, controller);;
}
