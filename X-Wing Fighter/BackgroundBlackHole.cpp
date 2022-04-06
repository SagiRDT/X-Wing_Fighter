#include "BackgroundBlackHole.h"

//Black Hole Builder
BackgroundBlackHole::BackgroundBlackHole(int randX, sf::Texture& texture)
	:BackgroundObj(sf::Vector2f(float(1000 + randX), -10.0F), texture)
{
	//set the animation frames and play it
	initAnimationFrames();
	play();
}

//Black hole destructor
BackgroundBlackHole::~BackgroundBlackHole()
{
}

//initializing all the sprite animation frames
void BackgroundBlackHole::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(186, 0, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(382, 0, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(578, 0, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(769, 0, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(0, 186, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(186, 186, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(382, 186, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(578, 186, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(769, 186, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(0, 375, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(186, 375, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(382, 375, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(578, 375, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(769, 375, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(0, 568, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(186, 568, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(382, 568, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(578, 568, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(769, 568, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(0, 760, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(186, 769, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(382, 769, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(578, 769, 191, 191));
	m_animationRegular.addFrame(sf::IntRect(769, 769, 191, 191));
}

