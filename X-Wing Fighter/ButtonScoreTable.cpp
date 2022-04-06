#include "ButtonScoreTable.h"

//ButtonScoreTable builder
ButtonScoreTable::ButtonScoreTable(sf::Vector2f position, std::string pathToTexture)
	:Button(position, pathToTexture)
{
	//add the animations of the button for mouse over mode and regular mode
	m_animationRegular.addFrame(sf::IntRect(0, 15, 350, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 75, 350, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 135, 350, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 195, 350, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 255, 350, 51));

	m_animationMouseOver.addFrame(sf::IntRect(350, 15, 350, 51));
	m_animationMouseOver.addFrame(sf::IntRect(350, 75, 350, 51));
	m_animationMouseOver.addFrame(sf::IntRect(350, 135, 350, 51));
	m_animationMouseOver.addFrame(sf::IntRect(350, 195, 350, 51));
	m_animationMouseOver.addFrame(sf::IntRect(350, 255, 350, 51));
}

//ButtonScoreTable destructor
ButtonScoreTable::~ButtonScoreTable()
{
}

//executing the button command - showing the score table
void ButtonScoreTable::executeCommand(sf::RenderWindow & window, Menu & menu)
{
}
