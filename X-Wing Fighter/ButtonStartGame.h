#pragma once
#include "Button.h"

class Menu;

class ButtonStartGame :
	public Button
{
public:
	void initAnimationFrames();
	ButtonStartGame(sf::Vector2f position, std::string pathToTexture);
	~ButtonStartGame();

	virtual void executeCommand(sf::RenderWindow& window, Menu &menu);
};

