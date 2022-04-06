#include "ButtonHowToPlay.h"
#include "Menu.h"

//ButtonHowToPlay builder
ButtonHowToPlay::ButtonHowToPlay(sf::Vector2f position, std::string pathToTexture)
	:Button(position, pathToTexture)
{
	//add the animations of the button for mouse over mode and regular mode
	m_animationRegular.addFrame(sf::IntRect(0, 0, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 57, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 114, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 169, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 224, 295, 51));

	m_animationMouseOver.addFrame(sf::IntRect(296, 0, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 56, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 113, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 168, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 223, 295, 51));
}

//ButtonHowToPlay destructor
ButtonHowToPlay::~ButtonHowToPlay()
{
}

//executing the button command - changing the how to play img in the menu to visible\invisible
void ButtonHowToPlay::executeCommand(sf::RenderWindow & window, Menu & menu)
{
	menu.changeHowTowPlayStat();
}
