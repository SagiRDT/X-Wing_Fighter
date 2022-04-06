#pragma once
#include "Button.h"

class ButtonScoreTable :
	public Button
{
public:
	ButtonScoreTable(sf::Vector2f position, std::string pathToTexture);
	~ButtonScoreTable();
	virtual void executeCommand(sf::RenderWindow& window, Menu &menu);
};

