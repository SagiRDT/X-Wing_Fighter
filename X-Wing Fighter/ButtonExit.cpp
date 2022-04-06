#include "ButtonExit.h"

//Exit button builder
ButtonExit::ButtonExit(sf::Vector2f position, std::string pathToTexture)
	:Button(position, pathToTexture)
{
	//add the animations of the button for mouse over mode and regular mode
	m_animationRegular.addFrame(sf::IntRect(0, 0, 120, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 50, 120, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 100, 120, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 150, 120, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 200, 120, 51));

	m_animationMouseOver.addFrame(sf::IntRect(121, 0, 130, 51));
	m_animationMouseOver.addFrame(sf::IntRect(121, 50, 130, 51));
	m_animationMouseOver.addFrame(sf::IntRect(121, 100, 130, 51));
	m_animationMouseOver.addFrame(sf::IntRect(121, 150, 130, 51));
	m_animationMouseOver.addFrame(sf::IntRect(121, 200, 130, 51));
}

//Exit button destructor
ButtonExit::~ButtonExit()
{
}

//executing the button command - exiting the program
void ButtonExit::executeCommand(sf::RenderWindow & window, Menu& menu)
{
	exit(0);
}
