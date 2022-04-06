#include "WeaponLaser.h"
#include <SFML\System\Time.hpp>
#include "SpaceshipEnemySimple.h"

WeaponLaser::WeaponLaser(sf::Vector2f position, sf::Sprite& sprite, sf::Sound& sound, int dir)
	:Weapon(position, sprite, 25)
{
	initAnimationFrames();
	m_speed = sf::Vector2f(0, float(-50.0 * dir));

	//sound effect
	sound.play();
}

WeaponLaser::WeaponLaser(sf::Vector2f position, sf::Texture& texture, sf::Sound& sound, int dir)
	:Weapon(position, texture, 25)
{

	initAnimationFrames();
	m_speed = sf::Vector2f(0, float(-50.0 * dir));
	sf::Int64 soundOffset = sound.getPlayingOffset().asMicroseconds();

 	if(soundOffset == 0 || soundOffset > sf::Int64(80000))
 		sound.play();
	play();//this is the play() of the animatedSprite needed to be done to set the sprite
}


WeaponLaser::~WeaponLaser()
{
}
//draw the laser
void WeaponLaser::draw(sf::RenderWindow& window)
{
	window.draw(m_animatedSprite);
}

//move the laser
void WeaponLaser::move(MoveDirection direction, Controller& controller)
{
	m_animatedSprite.setPosition(m_animatedSprite.getPosition() + m_speed);
}
//set the animation frames
void WeaponLaser::initAnimationFrames()
{
	m_animationRegular.setSpriteSheet(m_texture);
	m_animationRegular.addFrame(sf::IntRect(0, 0, 20, 80));
}
