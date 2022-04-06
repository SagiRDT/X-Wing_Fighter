#include "BackgroundStar.h"

//Star Builder
BackgroundStar::BackgroundStar(int randX, sf::Texture & texture)
	:BackgroundObj(sf::Vector2f(float(1000 + randX), -10.0F), texture)
{
	//set the animation frames and play it
	initAnimationFrames();
	play();
}

//Star destructor
BackgroundStar::~BackgroundStar()
{
}

//initializing all the sprite animation frames
void BackgroundStar::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 20, 20));
	m_animationRegular.addFrame(sf::IntRect(20, 0, 20, 20));
	m_animationRegular.addFrame(sf::IntRect(40, 0, 20, 20));
	m_animationRegular.addFrame(sf::IntRect(60, 0, 20, 20));
	m_animationRegular.addFrame(sf::IntRect(80, 0, 20, 20));
}
