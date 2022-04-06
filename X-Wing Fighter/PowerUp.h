#pragma once
#include "GameObj.h"

class SpaceshipPlayer;

class PowerUp :
	public GameObj
{
public:
	PowerUp(sf::Vector2f position, sf::Texture& texture);
	virtual ~PowerUp();

	virtual bool collide(GameObj* obj, Controller& controller);
	virtual bool collide(Weapon* wpn, Controller& controller) { return false; };

	virtual void initAnimationFrames();
	virtual void draw(sf::RenderWindow& window);
	virtual void move(MoveDirection direction, Controller& controller);
};

