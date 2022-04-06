#pragma once
#include "GameObj.h"

class BackgroundObj :
	public GameObj
{
public:
	BackgroundObj(sf::Vector2f position, sf::Texture& texture);
	virtual ~BackgroundObj();
	virtual void draw(sf::RenderWindow& window);
	virtual void move(MoveDirection direction, Controller& controller);
	virtual bool collide(GameObj* obj, Controller& controller);
	virtual bool collide(Weapon* wpn, Controller& controller) { return false; };
	virtual bool collide(Spaceship* spcship, Controller& controller) { return false; };

private:
	int m_speed;
};

