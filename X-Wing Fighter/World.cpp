#include "World.h"
#include "GameObj.h"
#include "Controller.h"
#include "Spaceship.h"
#include "PowerUpAmmo.h"
#include "PowerUpLife.h"
#include "PowerUpDelay.h"
#include "BackgroundBlackHole.h"
#include "BackgroundStar.h"
#include "BackgroundStar2.h"

//world builder - build the world with the first background as defualt
World::World()
{
	//load the background of the first stage
	loadTexture("../Textures/Background/bg_hd.png");
}

//world destructor
World::~World()
{
}

//loading a texture for game object, if it fails exit the game
void World::loadTexture(std::string path)
{
	if (!m_texture.loadFromFile(path))
		exit(EXIT_FAILURE);
	m_sprite.setTexture(m_texture);
}

//switching the world background with th ebackground image that was entered
void World::switchBackground(std::string path)
{
	//load the background from the path we entered
	loadTexture(path);
}

//draws the world on the RenderWindow and all the static objects the wolrd's containing
void World::draw(sf::RenderWindow & window)
{
	//draw the background
	window.draw(m_sprite);
			
	//draw the objects
	//background objects - drawing first to dray the rest over them
	for (const auto& obj : m_worldBGObjects)
	{
		obj->play();
		obj->draw(window);
	}
	//collidable objects
	for (const auto& obj : m_worldObjects)
	{
		obj->play();
		obj->draw(window);
	}
}
//clears all the objects from the world
void World::removeAll()
{
	m_worldObjects.clear();
	m_soonToBeCreatedExp.clear();
	m_soonToBeDeletedObj.clear();
}

//evolving the world and moving all the object a few steps forwards
void World::evolveWorld(Controller& controller)
{
	//check if there are explosion that need to go ka-boom!
	createExplosions(controller);
	//create new power ups
	summonObjects(controller);
	//clear objects that gone out of the screen
	clearGoneObjects();

	//move all the object of the board forward by x,y pixels
	for (std::vector<std::unique_ptr<GameObj>>::iterator it = m_worldObjects.begin(); it != m_worldObjects.end(); it++)
	{
		//(*it)->setPosition( (*it)->getPosition() + sf::Vector2f(0, -30) );

		(*it)->move( NONE, controller);
	}
	for (std::vector<std::unique_ptr<GameObj>>::iterator it = m_worldBGObjects.begin(); it != m_worldBGObjects.end(); it++)
	{
		//(*it)->setPosition( (*it)->getPosition() + sf::Vector2f(0, -30) );

		(*it)->move(NONE, controller);
	}
}
//gets one ship and checks the collisions of it with all the collidable objects
void World::checkWorldObjCollisions(Spaceship* ship, Controller& controller)
{
	for (auto it = m_worldObjects.begin(); it != m_worldObjects.end();)
	{
		if ((*it)->isCollided(ship))//if there is a collision
		{
			if((*it)->collide((Spaceship*)ship, controller))//theck if to delete the collided object
				it = m_worldObjects.erase(it);
			else
				++it;
		}
		else {
			++it;
		}
	}	
}

//this function creates PowerUp objects and background objects by random by the top edge of the screen
void World::summonObjects(Controller& controller)
{
	//===== random number generator from: http://en.cppreference.com/w/cpp/numeric/random =========
	// Seed with a real random value, if available
	std::random_device r,x;
	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r()), eX(x());
	std::uniform_int_distribution<int> uniform_dist_r(0, 1000), uniform_dist_x(-900, 900);
	// ==== end of random generator =====
	int random = uniform_dist_r(e1);
	int rndX = uniform_dist_x(eX);
	
	if (random == 0)//summon health
		m_worldObjects.emplace_back(std::make_unique<PowerUpAmmo>(rndX, controller.getPowerUpAmmoTexture2(), 2));//2 ammo to add
	if (random == 1)
		m_worldObjects.emplace_back(std::make_unique<PowerUpAmmo>(rndX, controller.getPowerUpAmmoTexture3(), 3));//3 ammo to add
	if (random == 2)
		m_worldObjects.emplace_back(std::make_unique<PowerUpLife>(rndX, controller.getPowerUpLifeTexture(), 1));//1 life to add
	if(random == 3)
		m_worldObjects.emplace_back(std::make_unique<PowerUpDelay>(rndX, controller.getPowerUpDelayTexture(), 0.5F));//decreace the delay by 2 times
	//background objects
	if (random ==5)
		m_worldBGObjects.emplace_back(std::make_unique<BackgroundStar>(rndX, controller.getStarTexture()));
	if (random ==6)
		m_worldBGObjects.emplace_back(std::make_unique<BackgroundStar2>(rndX, controller.getStarTexture2()));

}
//clears all objects that gone out of the screen
void World::clearGoneObjects()
{
	//collidable objects
	for (auto it = m_worldObjects.begin(); it != m_worldObjects.end(); ++it)
	{
		sf::Vector2f pos = (*it)->getPosition();
		if (pos.x > float(SCREEN_X + 100) || pos.x < -100.0F || pos.y > float(SCREEN_Y + 100) || pos.y < -100.0F)
		{
			m_worldObjects.erase(it);
			break;//iterator safety
		}
	}
	//background objects
	for (auto it = m_worldBGObjects.begin(); it != m_worldBGObjects.end(); ++it)
	{
		sf::Vector2f pos = (*it)->getPosition();
		if (pos.x > float(SCREEN_X + 100) || pos.x < -100.0F || pos.y > float(SCREEN_Y + 100) || pos.y < -100.0F)
		{
			m_worldBGObjects.erase(it);
			break;//iterator safety
		}
	}
}
//this function creates explosions in placees where ships exploded
void World::createExplosions(Controller& controller)
{
	if (m_soonToBeCreatedExp.size() == 0)
		return;

	//add all the explosion to the world objects array
	for (unsigned i = 0; i < m_soonToBeCreatedExp.size(); i++)
	{
		addWorldObject(std::make_unique<Explosion>(m_soonToBeCreatedExp[i], controller.getExplosionTexture(), controller.getExplosionSound()));
	}
	//init the soon to be created explosion vector
	m_soonToBeCreatedExp.clear();
}