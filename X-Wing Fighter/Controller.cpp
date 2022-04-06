#include "Controller.h"

#define MAX_ENEMY_SHIPS 3

Controller::Controller()
{
	//The Text
	//font
	if (!m_font.loadFromFile("../Fonts/Starjedi.ttf"))
		exit(EXIT_FAILURE);
	//hp
	m_hpTxt = sf::Text(m_hpStr, m_font, 45);
	m_hpTxt.setColor(sf::Color(44, 80, 255));
	m_hpTxt.setPosition(sf::Vector2f(20, 20));
	m_hpTxt.setStyle(sf::Text::Bold);
	//lives
	m_livesTxt = sf::Text(m_livesStr, m_font, 45);
	m_livesTxt.setColor(sf::Color(44, 80, 255));
	m_livesTxt.setPosition(sf::Vector2f(700, 20));
	m_livesTxt.setStyle(sf::Text::Bold);
	//score
	m_scoreTxt = sf::Text(m_scoreStr, m_font, 45);
	m_scoreTxt.setColor(sf::Color(44, 80, 255));
	m_scoreTxt.setPosition(sf::Vector2f(1400, 20));
	m_scoreTxt.setStyle(sf::Text::Bold);
	//ammo
	m_ammoTxt = sf::Text(m_ammoStr, m_font, 45);
	m_ammoTxt.setColor(sf::Color(44, 80, 255));
	m_ammoTxt.setPosition(sf::Vector2f(20, 1000));
	m_ammoTxt.setStyle(sf::Text::Bold);
	//game over
	m_gameOverTxt = sf::Text("# game over!! #", m_font, 120);
	m_gameOverTxt.setColor(sf::Color(255, 215, 0));
	m_gameOverTxt.setPosition(sf::Vector2f(380, 400));
	m_gameOverTxt.setStyle(sf::Text::Bold);
	m_gameOver2Txt = sf::Text("press Esc to go back to the menu", m_font, 80);
	m_gameOver2Txt.setColor(sf::Color(255, 215, 0));
	m_gameOver2Txt.setPosition(sf::Vector2f(180, 600));

	loadTextures();
	loadSounds();

	//icons while in-game playing
	//missile icon
	m_missileIcon.setTexture(m_missileAmmoTexture);
	m_missileIcon.setPosition(240, 1000);

	//add player spaceship
	m_playerSpaceship = std::make_unique<SpaceshipPlayer>(sf::Vector2f(850.0, 900.0),"../Textures/xwing_all2.png", 3);

	//the world
	m_world = std::make_unique<World>();
	//the menu
	m_menu = std::make_unique<Menu>(m_font);
}


Controller::~Controller()
{
}
//this function starts the game - from the menu - and runs until new game button is pressed
void Controller::startGame()
{
	//defines the game window
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "X-Wing Fighter");
	window.setVerticalSyncEnabled(true);
	window.setJoystickThreshold(10000);

		while (window.isOpen())
		{
			sf::Event event;
			sf::Vector2f mouseCoords;	//where mouse was pressed/moved
			if (window.pollEvent(event))
			{
				switch (event.type)
				{//close the window if X button was pressed
				case sf::Event::Closed:
					window.close();
					exit(0);
					break;
				case sf::Event::MouseMoved:
					mouseCoords = window.mapPixelToCoords({ event.mouseMove.x,event.mouseMove.y });  //get the mouse move coordinates
					m_menu->gotMoved(window, mouseCoords);
					break;
				case sf::Event::MouseButtonPressed:  //when the mouse was pressed, check where it was
					mouseCoords = window.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });  //get the mouse click coordinates
					m_menu->gotClicked(window, mouseCoords);
					break;
					//push escape while in game-pause to resume the game
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Escape)
					{
						//_RPT1(0,"escape key pressed while menu is active\n", 0);
						//setMenuUnActive if there is a game started
						if (m_isPaused)
							m_menu->setActive(false);
					}
				default:
					break;
				}
				//handle the pause menu, the user can decide to start a new game or to resume the current game
			if (!m_menu->isActive())//start new game
				if (m_isPaused && m_menu->isNewGame())
				{
					m_menu->setDisplayResumeText(false);
					m_isPaused = false;
					restartGame(window);
					runGame(window);
				}
				else//resume current game
				{
					m_isPaused = false;
					m_menu->setNewGame(false);
					runGame(window);
				}
			//if in pause menu display the message
			if (m_isPaused)
				m_menu->setDisplayResumeText(true);
			window.clear();
			m_menu->draw(window);
			window.display();
		}
	}
}
//this function runs the actual game
void Controller::runGame(sf::RenderWindow& window)
{
	while (window.isOpen())
	{

		sf::Event event;
		sf::Vector2f mouseCoords;	//where mouse was pressed
		
		//reset the ship postion to face forward after half sec of not moving
		if ((m_clock.getElapsedTime().asSeconds()) > 0.5)
		{
			m_playerSpaceship->setAnimation(UP);
			m_clock.restart();
		}

		//evolve the world and the object in it
			m_world->evolveWorld(*this);
			m_WorldClock.restart();

		window.clear();							//looking for something to happen
		if (window.pollEvent(event))
		{
			switch (event.type)
			{//close the window if X button was pressed
			case sf::Event::Closed:
				window.close();
				exit(0);
				break;
				//go to the pause menu
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					//_RPT1(0, "escape key pressed while in game\n", 0);
					m_isPaused = true;
					//setMenuActive 
					m_menu->setActive(true);
					//m_menu->setNewGame(false);
					return;
				}
			default:
				break;
			}
		}
		//listen to player moves
		listenToKeyBoard();

		//check collisions
		checkCollisions();

		//spawn enemy ships and get rid of those who gone out of the range
		spawnRandomEnemySpaceship();

		//=========================== DRAW =============================
		draw(window);
		 //===================== MOVE ENEMIES ============================
		moveEnemies(window);
		window.display();
	}
}
//this function restarts the game - initializing all menu and controller values
void Controller::restartGame(sf::RenderWindow& window)
{
	m_gameOver = false;
	m_soundGameover.pause();
	window.clear();
	m_world->removeAll();
	m_spaceships.clear();
	m_menu.reset(new Menu(m_font));
	m_playerSpaceship.reset(new SpaceshipPlayer(sf::Vector2f(850.0, 900.0), "../Textures/xwing_all2.png", 3));
}

//delete a ship that was destroyed
void Controller::deleteSpaceship(sf::Vector2f loc)
{
	//if a ship was destroyed update the player score and delete it from the enemy ships vector
	for (auto it = m_spaceships.begin(); it != m_spaceships.end(); ++it)
		if ((*it)->getPosition() == loc)
		{
			m_playerSpaceship->addScore((*it)->getWorthPoints());
			m_spaceships.erase(it);
			break;
		}
}

//check if there are ships that need to be destroyed and destroy them
void Controller::checkShipsToDestroy() 
{
	//if the vector of the ships that need to be destroyed is empty, exit the function
	if (m_shipsToBeDestroyed.size() == 0)
		return;

	//add all the explosion to the world objects array
	for (unsigned i = 0; i < m_shipsToBeDestroyed.size(); i++)
	{
		deleteSpaceship(m_shipsToBeDestroyed[i]);
	}
	//init the soon to be created explosion vector
	m_shipsToBeDestroyed.clear();
}

//this function gets the closest (to me - position) enemy spaceship position 
sf::Vector2f Controller::getClosestEnemyPosition(sf::Vector2f me)
{
	sf::Vector2f closestPos(0, 0);//default position
	float closestRange = 10000.0F;//starting range, sure we will found someone closer than this
	//go through all the enemy spaceships and find the closest
	for (const auto& enemy : m_spaceships)
	{
		sf::Vector2f enemyPos = enemy->getPosition();//current enemy we checking
		float currRange = std::sqrt(std::pow((enemyPos.x - me.x), 2) + std::pow((enemyPos.y - me.y), 2));
		if (currRange < closestRange)//if it is closer than the one we already have take it
		{
			closestPos = enemyPos;
			closestRange = currRange;
		}
	}
	return closestPos;
}
//this function loads all sounds
void Controller::loadSounds()
{
	if (!m_playerLaserSoundBuffer.loadFromFile("../Sounds/XWing-Laser.wav"))
		exit(1);
	else
		m_playerLaserSound.setBuffer(m_playerLaserSoundBuffer);

	if (!m_enemyLaserSoundBuffer.loadFromFile("../Sounds/TIE-Laser.wav")) 
		exit(1);
	else
		m_enemyLaserSound.setBuffer(m_enemyLaserSoundBuffer);

	if (!m_sbufferGameover.loadFromFile("../Sounds/imperial.wav"))
		exit(EXIT_FAILURE);
	else
		m_soundGameover.setBuffer(m_sbufferGameover);
	//loading and playing the explosion sound
	if (!m_explosionSB.loadFromFile("../Sounds/explosion.wav"))
		exit(1);
	else
		m_explosionSound.setBuffer(m_explosionSB);
}
//this function loads all textures
void Controller::loadTextures()
{
	if(!m_playerlaserTexture.loadFromFile("../Textures/laser_player.png"))
		exit(1);
	if (!m_enemylaserTexture.loadFromFile("../Textures/laser_enemy.png"))
		exit(1);
	if (!m_missileTexture.loadFromFile("../Textures/missile_2.png"))
		exit(1);
	if (!m_missileAmmoTexture.loadFromFile("../Textures/Missile_icon.png"))
		exit(1);
	if (!m_powerUpAmmoTexture2.loadFromFile("../Textures/powerup_ammo2.png"))
		exit(1);
	if (!m_powerUpAmmoTexture3.loadFromFile("../Textures/powerup_ammo3.png"))
		exit(1);
	if (!m_powerUpLife.loadFromFile("../Textures/powerup_life.png"))
		exit(1);
	if (!m_powerUpDelay.loadFromFile("../Textures/powerup_delay.png"))
		exit(1);
	if (!m_bgBlackHole.loadFromFile("../Textures/black.png"))
		exit(1);
	if (!m_bgStar.loadFromFile("../Textures/star.png"))
		exit(1);
	if (!m_bgStar2.loadFromFile("../Textures/star2.png"))
		exit(1);
	if (!m_explosionTexture.loadFromFile("../Textures/explosion.png"))
		exit(1);
}
//listens to keyboard and runs the appropriate functions
void Controller::listenToKeyBoard()
{
	//========================= PLAYER MOVE ======= KEYBOARD ==============
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//_RPT1(0, "new pos: %f, %f\n", m_spaceships[0]->getPosition().x, m_spaceships[0]->getPosition().y);
		m_playerSpaceship->move(UP, *this);
		m_clock.restart();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_playerSpaceship->move(DOWN, *this);
		m_clock.restart();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerSpaceship->move(LEFT, *this);
		m_clock.restart();

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_playerSpaceship->move(RIGHT, *this);
		m_clock.restart();
	}
	//fire lase
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_playerSpaceship->shoot(PLAYER, LASER, *this);
	}
	//fire missiles
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		m_playerSpaceship->shoot(PLAYER, MISSILE, *this);
	}
}

void Controller::moveEnemies(sf::RenderWindow& window)
{
	if (m_spaceships.size() > 0)
		for (const auto& spaceship : m_spaceships)
		{
			if (!m_gameOver)
				spaceship->move(NONE, *this);
			spaceship->play();
			spaceship->draw(window);
		}
}

//this function spawns(or not - by random) enemy spaceship, not boss
void Controller::spawnRandomEnemySpaceship()
{
	if (m_spaceships.size() >= MAX_ENEMY_SHIPS)
		return;
	//===== random number generator from: http://en.cppreference.com/w/cpp/numeric/random =========
	// Seed with a real random value, if available

	//random ship
	std::random_device r_chooseShip;
	std::default_random_engine e_chooseShip(r_chooseShip());
	std::uniform_int_distribution<int> uniform_dist_chooseShip(0, 10);
	int chooseShip = uniform_dist_chooseShip(e_chooseShip);
	//random location
	std::random_device r_locX;
	std::random_device r_locY;

	std::default_random_engine e_locX(r_chooseShip());
	std::default_random_engine e_locY(r_chooseShip());

	std::uniform_int_distribution<int> uniform_dist_locX(-300, 300);
	std::uniform_int_distribution<int> uniform_dist_locY(-100, 100);
	//get the random location
	int locX = uniform_dist_locX(e_locX);
	int locY = uniform_dist_locY(e_locY);

	// ==== end of random generator =====
	
	switch (chooseShip)
	{
	case 0://spawn simple enemy spaceship 

		m_spaceships.emplace_back(std::make_unique<SpaceshipEnemySimple>(sf::Vector2f(float(1000.0 + locX), float(200.0 + locY)), "../Textures/tie_simple_all.png"));
		break;
	case 1://spawn advanced enemy spaceship 
		m_spaceships.emplace_back(std::make_unique<SpaceshipEnemyAdvanced>(sf::Vector2f(float(1000.0 + locX), float(200.0 + locY)), "../Textures/tie_advanced_all.png"));
		break;
	//future use
	//case 2://spawn boss enemy spaceship

	//	break;

	default:
		break;
	}
}

//this function checking all the spaceships collisions with the relevant(not background) world's objects
void Controller::checkCollisions()
{
	//check for each ship if it collided with some world object
	for (auto it = m_spaceships.begin(); it != m_spaceships.end(); ++it)
	{
		m_world->checkWorldObjCollisions((*it).get(), *this);
	}
	//check if player ship collided with enemy ship
	m_world->checkWorldObjCollisions(m_playerSpaceship.get(), *this);

	//if there are ships that need to be destroyed - destroy it
	checkShipsToDestroy();
}
//this function draws everything
void Controller::draw(sf::RenderWindow& window)
{
	//draw the world background
	m_world->draw(window);
	//draw the info on the screen (hp, lives, score etc)
	drawPlayerInfo(window);
	//draw the spaceships
	//if the player isnt dead draw him
	if (!m_playerSpaceship->isDead())
	{
		m_playerSpaceship->play();
		m_playerSpaceship->draw(window);
	}
}
//this function draws the player info: lives, health, ammo...
void Controller::drawPlayerInfo(sf::RenderWindow& window)
{
	window.draw(m_hpTxt);
	window.draw(m_livesTxt);
	window.draw(m_scoreTxt);
	window.draw(m_ammoTxt);

	//if the game is over show the game over text
	if (m_gameOver) {
		window.draw(m_gameOverTxt);
		window.draw(m_gameOver2Txt);
	}
		
	updatePlayerHp();
	updatePlayerLives();
	updateScore();

	//draw the missles the player have
	sf::Vector2f missileIconPos = m_missileIcon.getPosition();
	for (auto missileNum = 0; missileNum < m_playerSpaceship->getAmmo()[1]; missileNum++) {
		window.draw(m_missileIcon);
		missileIconPos += sf::Vector2f(25, 0);
		m_missileIcon.setPosition(missileIconPos);
	}
	//init the mision icon pos
	m_missileIcon.setPosition(240, 1000);

}

//update the player hp
void Controller::updatePlayerHp()
{
	char temp[15] = "Hp: ";
	char temp2[5];
	_itoa_s(m_playerSpaceship->getHp(), temp2, 10);
	strcat_s(temp, temp2);
	strcat_s(temp, " %");
	m_hpTxt.setString(temp);
}

//update the player lives
void Controller::updatePlayerLives()
{
	char temp[15] = "Lives: ";
	for ( auto i = 0; i < m_playerSpaceship->getLives(); i++)
		strcat_s(temp, "$ ");
	m_livesTxt.setString(temp);
}

//updates points counter on the screen
void Controller::updateScore()
{
	char temp[15] = "Score: ";
	char temp2[6];
	_itoa_s(m_playerSpaceship->getScore(), temp2, 10);
	strcat_s(temp, temp2);
	m_scoreTxt.setString(temp);
}
//display the game over text
void Controller::gameOver()
{
	m_gameOver = true;

	m_soundGameover.play();
	m_menu->stopBgMusic();

	//m_menu->gameOver();
	m_menu->setActive(true);
}