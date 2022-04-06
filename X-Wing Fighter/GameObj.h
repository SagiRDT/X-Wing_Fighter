#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<cstdlib>
#include <memory>
#include"AnimatedSprite.h"

class Controller;
class Weapon;
class Spaceship;
class PowerUpAmmo;
class PowerUpLife;
class PowerUpDelay;

enum MoveDirection { LEFT, RIGHT, DOWN, UP, NONE };

class GameObj
{
public:
	GameObj();
	GameObj(sf::Vector2f position, sf::Sprite& sprite);
	GameObj(sf::Vector2f position, sf::Texture& texture);
	GameObj(sf::Vector2f position, std::string& path);
	virtual ~GameObj();

	//return the object position
	sf::Vector2f getPosition() const { return m_animatedSprite.getPosition(); }
	//changing the object position
	void setPosition(sf::Vector2f& pos) { m_animatedSprite.setPosition(pos); }
	void loadTexture(std::string path);
	virtual bool isCollided(GameObj*);

	AnimatedSprite& getSprite() { return m_animatedSprite; }

	void play();

	//virtual functions
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void move(MoveDirection direction, Controller& controller) = 0;
	virtual void initAnimationFrames() = 0;

	virtual bool collide(GameObj* obj, Controller& controller) = 0;
	virtual bool collide(Weapon* wpn, Controller& controller) = 0;
	virtual bool collide(Spaceship* spcship, Controller& controller) = 0;
	
	//powerup spesific collides
	virtual bool collide(PowerUpAmmo* pwup, Controller& controller) { return false; };
	virtual bool collide(PowerUpLife* pwup, Controller& controller) { return false; };
	virtual bool collide(PowerUpDelay* pwup, Controller& controller) { return false; };

protected:

	//textures and sprites
	sf::Texture m_texture;
	AnimatedSprite m_animatedSprite;
	Animation m_animationRegular;
	Animation* m_currentAnimation;
	int m_numOfSprites;
	int m_currSprite;
};

