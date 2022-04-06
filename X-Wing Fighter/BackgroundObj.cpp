#include "BackgroundObj.h"
#include <random>

//Background Obj Builder
BackgroundObj::BackgroundObj(sf::Vector2f position, sf::Texture& texture)
	:GameObj(position, texture)
{
	//===== random number generator from: http://en.cppreference.com/w/cpp/numeric/random =========
	// Seed with a real random value, if available
	std::random_device r;
	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist_r(1, 3);
	// ==== end of random generator =====
	int random = uniform_dist_r(e1);
	m_speed = random;
}

//Background Obj destructor
BackgroundObj::~BackgroundObj()
{
}

//Draw a background obj
void BackgroundObj::draw(sf::RenderWindow & window)
{
	window.draw(m_animatedSprite);
}

//Move the background obj
void BackgroundObj::move(MoveDirection direction, Controller & controller)
{
	m_animatedSprite.move(0.0, float(m_speed));//constant "down" direction
}

//collide with game obj
//calls the obj collide function with the background obj via polymorphism
bool BackgroundObj::collide(GameObj * obj, Controller & controller)
{
	return obj->collide(this, controller);;
}
