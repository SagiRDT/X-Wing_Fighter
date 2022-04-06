#include "BackgroundStar2.h"

//Star2 Builder
BackgroundStar2::BackgroundStar2(int randX, sf::Texture & texture)
	:BackgroundObj(sf::Vector2f(float(1000 + randX), -10.0F), texture)
{
	//set the animation frames and play it
	initAnimationFrames();
	play();
}

//Star2 destructor
BackgroundStar2::~BackgroundStar2()
{
}

//initializing all the sprite animation frames
void BackgroundStar2::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(92 * 0, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 0, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 0, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 1, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 1, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 2, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 2, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 3, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 3, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 4, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 4, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 5, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 5, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 6, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 6, 92, 92));

	m_animationRegular.addFrame(sf::IntRect(92 * 0, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 1, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 2, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 3, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 4, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 5, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 6, 92 * 7, 92, 92));
	m_animationRegular.addFrame(sf::IntRect(92 * 7, 92 * 7, 92, 92));
}
