#pragma once
#include "Button.h"

class ButtonExit :
	public Button
{
public:
	ButtonExit(sf::Vector2f position, std::string pathToTexture);
	~ButtonExit();
	virtual void executeCommand(sf::RenderWindow& window, Menu &menu);
};

