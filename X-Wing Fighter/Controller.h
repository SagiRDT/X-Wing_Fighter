#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include"World.h"
#include"Menu.h"
#include"SpaceshipEnemySimple.h"
#include"SpaceshipEnemyAdvanced.h"
#include"SpaceshipEnemyBoss.h"
#include"SpaceshipPlayer.h"
#include <random>

class Controller
{
public:
	Controller();
	~Controller();

	void startGame();
	void runGame(sf::RenderWindow& window);
	void restartGame(sf::RenderWindow& window);

	sf::Texture& getPlayerLaserTexture() { return m_playerlaserTexture; }
	sf::Texture& getEnemyLaserTexture() { return m_enemylaserTexture; }
	sf::Texture& getMissileTexture() { return m_missileTexture; }
	sf::Texture& getPowerUpAmmoTexture2() { return m_powerUpAmmoTexture2; }
	sf::Texture& getPowerUpAmmoTexture3() { return m_powerUpAmmoTexture3; }
	sf::Texture& getPowerUpLifeTexture() { return m_powerUpLife; }
	sf::Texture& getPowerUpDelayTexture() { return m_powerUpDelay; }
	sf::Texture& getBlackHoleTexture() { return m_bgBlackHole; }
	sf::Texture& getStarTexture() { return m_bgStar; }
	sf::Texture& getStarTexture2() { return m_bgStar2; }
	sf::Texture& getExplosionTexture() { return m_explosionTexture; }
	std::unique_ptr<World>& getWorld() { return m_world; }
	
	void gameOver();

	sf::Vector2f getPlayerPos() { return m_playerSpaceship->getPosition(); }
	sf::Sound& getPlayerLaserSound() { return m_playerLaserSound; }
	sf::Sound& getEnemyLaserSound() { return m_enemyLaserSound; }
	sf::Sound& getExplosionSound() { return m_explosionSound; }

	void addToBeDestroyedShip(sf::Vector2f cords) { m_shipsToBeDestroyed.push_back(cords); }
	void deleteSpaceship(sf::Vector2f loc);
	void checkShipsToDestroy();

	void drawPlayerInfo(sf::RenderWindow& window);
	void updatePlayerHp();
	void updatePlayerLives();
	void updateScore();

	sf::Vector2f getClosestEnemyPosition(sf::Vector2f me);

private:

	void loadSounds();
	void loadTextures();
	void listenToKeyBoard();
	void moveEnemies(sf::RenderWindow& window);

	void spawnRandomEnemySpaceship();

	void checkCollisions();

	sf::Clock m_clock;
	sf::Clock m_WorldClock;

	void draw(sf::RenderWindow& window);

	bool m_gameOver = false;
	bool m_isPaused = false;

	//the palyer spaceship
	std::unique_ptr<SpaceshipPlayer> m_playerSpaceship;
	//the enemies spaceships
	std::vector<std::unique_ptr<SpaceshipEnemy>> m_spaceships;
	//vector that hold ships that are going to be destroyed
	std::vector<sf::Vector2f> m_shipsToBeDestroyed;
	
	std::unique_ptr<World> m_world;
	std::unique_ptr<Menu> m_menu;
	
	//Text
	sf::Font m_font;							//the font
	sf::Text m_hpTxt;							//text of the player hp
	sf::Text m_livesTxt;						//text of lives
	sf::Text m_scoreTxt;						//text of the player  score
	sf::Text m_ammoTxt;							//text of ammo
	sf::Text m_gameOverTxt;						//text of game over
	sf::Text m_gameOver2Txt;					//text of game over (the second part of the text)
	std::string m_hpStr = "HP: ";				//the hp in string
	std::string m_livesStr = "Lives: ";			//the lives in string
	std::string m_scoreStr = "Score: ";			//the score in string
	std::string m_ammoStr = "Missiles: ";		//the ammo in string

	//textures
	sf::Texture m_playerlaserTexture;
	sf::Texture m_enemylaserTexture;
	sf::Texture m_missileTexture;
	sf::Texture m_powerUpAmmoTexture2;
	sf::Texture m_powerUpAmmoTexture3;
	sf::Texture m_powerUpLife;
	sf::Texture m_powerUpDelay;
	sf::Texture m_bgBlackHole;
	sf::Texture m_bgStar;
	sf::Texture m_bgStar2;
	sf::Texture m_explosionTexture;
	//Text Textures
	sf::Texture m_missileAmmoTexture;
	//Icons Sprites
	sf::Sprite m_missileIcon;

	//sound buffers
	sf::SoundBuffer m_playerLaserSoundBuffer;
	sf::SoundBuffer m_enemyLaserSoundBuffer;
	sf::SoundBuffer m_sbufferGameover;
	sf::SoundBuffer m_explosionSB;
	//sounds
	sf::Sound m_playerLaserSound;
	sf::Sound m_enemyLaserSound;
	sf::Sound m_soundGameover;
	sf::Sound m_explosionSound;
};

