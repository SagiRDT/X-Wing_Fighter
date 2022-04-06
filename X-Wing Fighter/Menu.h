#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include"ButtonExit.h"
#include"ButtonHowToPlay.h"
#include"ButtonScoreTable.h"
#include"ButtonStartGame.h"
#include<vector>
#include<memory>
#include<SFML/Audio.hpp>

class Menu
{
public:
	Menu(sf::Font& font);
	~Menu();

	void draw(sf::RenderWindow& window);

	bool isActive() { return m_isActive; }
	bool isNewGame() { return m_newGame; }
	void setActive(bool isActive) { m_isActive = isActive; }
	void setNewGame(bool isSet) { m_newGame = isSet; }
	void setDisplayResumeText(bool set) { m_displayResumeText = set; }
	void gotMoved(sf::RenderWindow& window, sf::Vector2f coords);
	void gotClicked(sf::RenderWindow& window, sf::Vector2f coords);
	void changeHowTowPlayStat() { m_howToPlayActive = !m_howToPlayActive; }
	void stopBgMusic();

private:

	void setNormalPics();
	//resume text while is pause menu
	sf::Font m_font;
	sf::Text m_resumeText;

	//the texture and sprite
	sf::Sprite m_backGroundSprite;
	sf::Texture m_backGroundTexture;
	sf::Sprite m_howToPlay_sprite;
	sf::Texture m_howToPlay_texture;

	bool m_isActive;
	bool m_newGame;
	bool m_howToPlayActive;
	bool m_displayResumeText;

	std::vector<std::unique_ptr<Button>> m_buttons;
	std::vector<std::unique_ptr<Button>> m_buttonsText;

	//music
	sf::Music m_bgMusic;

	//texts
	sf::Text m_newGameText;
};

