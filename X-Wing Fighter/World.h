#pragma once
#include<SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
#include<memory>

#define SCREEN_X 1920
#define SCREEN_Y 1080

class GameObj;
class Spaceship;
class Clock;
class Controller;

class World
{
public:
	World();
	~World();

	virtual void draw(sf::RenderWindow& window);

	void removeAll();

	void loadTexture(std::string path);
	void switchBackground(std::string path);

	//return a pointer to the Obstacles vector
	std::vector<std::unique_ptr<GameObj>>& getObj() { return m_worldObjects; }

	void evolveWorld(Controller& controller);

	void addWorldObject(std::unique_ptr<GameObj> obj) { m_worldObjects.push_back(std::move(obj)); }
	void addWorldBGObject(std::unique_ptr<GameObj> obj) { m_worldBGObjects.push_back(std::move(obj)); }
	void addToBeCreatedExplosion(sf::Vector2f cords) { m_soonToBeCreatedExp.push_back(cords); }

	void checkWorldObjCollisions(Spaceship* extObject, Controller& controller);

	void createExplosions(Controller& controller);

private:

	void summonObjects(Controller& controller);
	void clearGoneObjects();


	//vectors for all the static objects on the board
	std::vector<std::unique_ptr<GameObj>> m_worldObjects;//collidable objects
	std::vector<std::unique_ptr<GameObj>> m_worldBGObjects;//background objects
	
	//vector to obj that are soon to be deleted
	std::vector<sf::Vector2f> m_soonToBeDeletedObj;
	//vector to explosions that are soon to be created
	std::vector<sf::Vector2f> m_soonToBeCreatedExp;

	//background texture and sprite
	sf::Sprite m_sprite;
	sf::Texture m_texture;

};

