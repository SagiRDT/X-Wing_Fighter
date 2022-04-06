#pragma once
#include "Spaceship.h"
#include "Weapon.h"
#include "PowerUp.h"

class PowerUpAmmo;
class PowerUpLife;
class PowerUpDelay;
#define MAX_HP 100

class SpaceshipPlayer :
	public Spaceship
{
public:
	SpaceshipPlayer(sf::Vector2f position, sf::Sprite& sprite, int lives);
	SpaceshipPlayer(sf::Vector2f position, std::string path, int lives);
	virtual ~SpaceshipPlayer();


	virtual void explode(Controller& controller) override;
	void dead(Controller& controller);

	void initAnimationFrames();

	virtual void move(MoveDirection direction, Controller& controller);

	sf::Vector2f getPosition() { return m_animatedSprite.getPosition(); }
	int getScore() { return m_score; }
	int getLives() { return m_lives; }


	virtual bool collide(PowerUpAmmo* pwup, Controller& controller);
	virtual bool collide(PowerUpLife* pwup, Controller& controller);
	virtual bool collide(PowerUpDelay* pwup, Controller& controller);

	void addAmmo(int ammo);
	void addLife(int lifes);
	void mulDelay(float multiplier);
	void addScore(int points) { m_score += points; }

	bool isDead() { return m_isDead; }

private:
	int m_lives;
	int m_score;
	bool m_isDead = false;
};

