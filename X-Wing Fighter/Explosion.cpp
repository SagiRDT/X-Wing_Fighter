#include "Explosion.h"
#include "Spaceship.h"

//Explosion contructor
Explosion::Explosion(sf::Vector2f pos, sf::Texture& texture, sf::Sound& sound)
	:GameObj(pos, texture)
{
	sound.play();

	//initing the sprites and playing the animation
	m_animationRegular.setSpriteSheet(m_texture);
	initAnimationFrames();
	m_animationRegular.setSpriteSheet(m_texture);
	play();
}

//Explosion destructor
Explosion::~Explosion()
{
}

//drawing the explosion on the window
void Explosion::draw(sf::RenderWindow & window)
{
	//if the animation ended get the object outsite the range - it will be deleted //
	if (m_timer.getElapsedTime() > sf::milliseconds(1500))
		m_animatedSprite.setPosition(-1000.0, -1000.0);
	window.draw(m_animatedSprite);
}

//move function - the explosion is static it dosnt move, just explode
void Explosion::move(MoveDirection direction, Controller & controller)
{
}

//initializing all the sprite animation frames
void Explosion::initAnimationFrames()
{
	m_animationRegular.addFrame(sf::IntRect(0, 0, 67, 67));//1
	m_animationRegular.addFrame(sf::IntRect(67, 0, 67, 67));//2
	m_animationRegular.addFrame(sf::IntRect(134, 0, 67, 67));//3
	m_animationRegular.addFrame(sf::IntRect(201, 0, 67, 67));//4
	m_animationRegular.addFrame(sf::IntRect(268, 0, 67, 67));//5
	m_animationRegular.addFrame(sf::IntRect(335, 0, 67, 67));//6
	m_animationRegular.addFrame(sf::IntRect(0, 67, 67, 67));//7
	m_animationRegular.addFrame(sf::IntRect(67, 67, 67, 67));//8
	m_animationRegular.addFrame(sf::IntRect(134, 67, 67, 67));//9
	m_animationRegular.addFrame(sf::IntRect(201, 67, 67, 67));//10
	m_animationRegular.addFrame(sf::IntRect(268, 67, 67, 67));//11
	m_animationRegular.addFrame(sf::IntRect(335, 67, 67, 67));//12
	m_animationRegular.addFrame(sf::IntRect(0, 134, 67, 67));//13
	m_animationRegular.addFrame(sf::IntRect(67, 134, 67, 67));//15
	m_animationRegular.addFrame(sf::IntRect(134, 134, 67, 67));//16
	m_animationRegular.addFrame(sf::IntRect(201, 134, 67, 67));//14
	m_animationRegular.addFrame(sf::IntRect(268, 134, 67, 67));//17
	m_animationRegular.addFrame(sf::IntRect(335, 134, 67, 67));//18
	m_animationRegular.addFrame(sf::IntRect(0, 201, 67, 67));//19
	m_animationRegular.addFrame(sf::IntRect(67, 201, 67, 67));//20
	m_animationRegular.addFrame(sf::IntRect(134, 201, 67, 67));//21
	m_animationRegular.addFrame(sf::IntRect(201, 201, 67, 67));//22
	m_animationRegular.addFrame(sf::IntRect(268, 201, 67, 67));//23
	m_animationRegular.addFrame(sf::IntRect(335, 201, 67, 67));//24
	m_animationRegular.addFrame(sf::IntRect(0, 268, 67, 67));//25
	m_animationRegular.addFrame(sf::IntRect(67, 268, 67, 67));//26
	m_animationRegular.addFrame(sf::IntRect(134, 268, 67, 67));//27
	m_animationRegular.addFrame(sf::IntRect(201, 268, 67, 67));//28
	m_animationRegular.addFrame(sf::IntRect(268, 268, 67, 67));//29
	m_animationRegular.addFrame(sf::IntRect(335, 268, 67, 67));//30
	m_animationRegular.addFrame(sf::IntRect(0, 335, 67, 67));//31
	m_animationRegular.addFrame(sf::IntRect(67, 335, 67, 67));//32
}

//explosion collide with game obj
bool Explosion::collide(GameObj * obj, Controller & controller)
{
	return obj->collide(this, controller);
}

//explosion collide with spaceship
bool Explosion::collide(Spaceship* ship, Controller & controller)
{
	return false;
}
