#pragma once
#include "Button.h"

class ButtonHowToPlay :
	public Button
{
public:
	ButtonHowToPlay(sf::Vector2f position, std::string pathToTexture);
	~ButtonHowToPlay();

	virtual void executeCommand(sf::RenderWindow& window, Menu &menu);

};

