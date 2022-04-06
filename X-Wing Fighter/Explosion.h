#pragma once
#include "GameObj.h"

class Explosion :
	public GameObj
{
public:
	Explosion(sf::Vector2f pos, sf::Texture& texture, sf::Sound& sound);
	virtual ~Explosion();

	virtual void draw(sf::RenderWindow& window);
	virtual void move(MoveDirection direction, Controller& controller);
	virtual void initAnimationFrames();

	virtual bool collide(GameObj* obj, Controller& controller);
	virtual bool collide(Spaceship* ship, Controller& controller);
	virtual bool collide(Weapon* ship, Controller& controller) { return false; };

private:

	sf::Clock m_timer;
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;
};

