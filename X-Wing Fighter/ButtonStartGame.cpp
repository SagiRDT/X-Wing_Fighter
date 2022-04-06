#include "ButtonStartGame.h"
#include "Menu.h"

//ButtonStartGame builder
ButtonStartGame::ButtonStartGame(sf::Vector2f position, std::string pathToTexture)
	:Button(position, pathToTexture)
{
	initAnimationFrames();
}

//ButtonStartGame destructor
ButtonStartGame::~ButtonStartGame()
{
}

//adding the animations of the button for mouse over mode and regular mode
void ButtonStartGame::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 56, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 112, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 168, 295, 51));
	m_animationRegular.addFrame(sf::IntRect(0, 223, 295, 51));

	m_animationMouseOver.addFrame(sf::IntRect(296, 0, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 56, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 112, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 168, 295, 51));
	m_animationMouseOver.addFrame(sf::IntRect(296, 223, 295, 51));
}

//executing the button command - starting a new game
void ButtonStartGame::executeCommand(sf::RenderWindow& window, Menu& menu)
{
	menu.setActive(false);
	menu.setNewGame(true);
}
