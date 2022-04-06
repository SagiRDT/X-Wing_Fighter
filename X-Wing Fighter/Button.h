#pragma once
#include<SFML\Graphics.hpp>
#include"AnimatedSprite.h"

class Menu;	// in order to aviod infinite includes loops

class Button
{
public:
	Button(sf::Vector2f position, std::string pathToTexture);
	//Button(sf::Vector2f position, sf::Text& text);
	virtual ~Button();

	void setAnimation(bool isMouseOver);
	void draw(sf::RenderWindow& window) { window.draw(m_animatedSprite); }
	bool checkCoords(sf::RenderWindow& window, sf::Vector2f& coords);
	virtual void executeCommand(sf::RenderWindow& window, Menu &menu) = 0;

	void play();

protected:
	sf::Texture m_texture;
	Animation m_animationRegular;
	Animation m_animationMouseOver;
	Animation* m_currentAnimation;
	AnimatedSprite m_animatedSprite;
};

