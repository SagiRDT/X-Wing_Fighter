#include "Menu.h"



Menu::Menu(sf::Font& font)
	:m_font(font)
{
	//init resume game text
	m_resumeText = sf::Text(std::string("press escape to resume the game"), m_font, 50);
	m_resumeText.setPosition(350.0F, 900.0F);
	m_resumeText.setColor(sf::Color(44, 80, 255));
	m_resumeText.setStyle(sf::Text::Underlined);
	//background picture
	if (!m_backGroundTexture.loadFromFile("../Textures/menu_background.png"))
		exit(2);
	m_backGroundSprite.setTexture(m_backGroundTexture);

	//load the how to play image
	if (!m_howToPlay_texture.loadFromFile("../Textures/HowToPlay.jpg"))
		exit(EXIT_FAILURE);
	m_howToPlay_sprite.setTexture(m_howToPlay_texture);
	m_howToPlay_sprite.setPosition(sf::Vector2f(1120, 480));

	//init the bool varibles
	m_isActive = true;
	m_newGame = false;
	m_howToPlayActive = false;


	//add buttons
	m_buttons.emplace_back(std::make_unique<ButtonStartGame>(sf::Vector2f(100.0, 100.0), "../Textures/new_game_all.png"));
	m_buttons.emplace_back(std::make_unique<ButtonExit>(sf::Vector2f(1750.0, 30.0), "../Textures/exit_all.png"));
	m_buttons.emplace_back(std::make_unique<ButtonHowToPlay>(sf::Vector2f(100.0, 250.0), "../Textures/controls_all.png"));
	m_buttons.emplace_back(std::make_unique<ButtonScoreTable>(sf::Vector2f(100.0, 400.0), "../Textures/top_all.png"));

	//music
	if (!m_bgMusic.openFromFile("../Sounds/menu_bg_music.ogg"))
		exit(2);
	m_bgMusic.play();
	m_bgMusic.setLoop(true);
}

//Menu destructor
Menu::~Menu()
{
}

//Drawing the menu
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_backGroundSprite);

	//draw the buttons
	for (auto& button : m_buttons)
	{
		button->play();
		button->draw(window);
	}
	
	//if m_howToPlayActive = true draw the how to play img
	if (m_howToPlayActive)
		window.draw(m_howToPlay_sprite);
	if (m_displayResumeText)
		window.draw(m_resumeText);
}

//change a button sprite if the mouse is over it
void Menu::gotMoved(sf::RenderWindow & window, sf::Vector2f coords)
{
	//return the buttons sprite to the normal 1 for the buttons that the mouse is not over them
	setNormalPics();
	for (std::vector<std::unique_ptr<Button>>::iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
	{
		if ((*it)->checkCoords(window, coords))
		{
			//call the buttons function
			(*it)->setAnimation(true);
			break;
		}
	}
}

//stop the animation of all the buttons (button animation should run only if the mouse over it)
void Menu::setNormalPics()
{
	for (std::vector<std::unique_ptr<Button>>::iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
		(*it)->setAnimation(false);
}

//check if the menu was clicked
//if any of the buttons was clicked call it function
void Menu::gotClicked(sf::RenderWindow& window, sf::Vector2f coords)
{

	for (std::vector<std::unique_ptr<Button>>::iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
	{
		if ((*it)->checkCoords(window, coords))
		{
			//call the buttons function
			(*it)->executeCommand(window, *this);
			break;
		}
	}
}

//stop the background music
void Menu::stopBgMusic()
{
	m_bgMusic.pause();
}