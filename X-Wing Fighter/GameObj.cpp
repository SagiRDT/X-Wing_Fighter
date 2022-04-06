#include "GameObj.h"

//GameObj builder
GameObj::GameObj()
{
}

//GameObj builder
GameObj::GameObj(sf::Vector2f position, sf::Sprite& sprite)
{
	//load the obj sprite and setting the obj position
	m_animatedSprite = AnimatedSprite(sf::seconds(0.2F));
	m_animatedSprite.setPosition(position);
	m_currentAnimation = &m_animationRegular;
}

//GameObj builder
GameObj::GameObj(sf::Vector2f position, sf::Texture& texture)
{
	m_texture = texture;

	//load the obj sprite and setting the obj position
	m_animatedSprite = AnimatedSprite(sf::seconds(0.2F), false, true);
	m_animationRegular.setSpriteSheet(m_texture);
	m_animatedSprite.setPosition(position);
	m_currentAnimation = &m_animationRegular;
}

//GameObj builder
GameObj::GameObj(sf::Vector2f position, std::string& path)
{
	if (!m_texture.loadFromFile(path))
		exit(EXIT_FAILURE);

	//load the obj sprite and setting the obj position
	m_animatedSprite = AnimatedSprite(sf::seconds(0.2F), false, true);
	m_animationRegular.setSpriteSheet(m_texture);
	m_animatedSprite.setPosition(position);
	m_currentAnimation = &m_animationRegular;
}

//GameObj destructor
GameObj::~GameObj()
{
}

//loading a texture for game object, if it fails exit the game
void GameObj::loadTexture(std::string path)
{
	if (!m_texture.loadFromFile(path))
		exit(EXIT_FAILURE);
	//m_sprite.setTexture(m_texture);
}

//check if the object collided with other object. return true if it is, else return false//
bool GameObj::isCollided(GameObj* obj)
{
	return m_animatedSprite.getGlobalBounds().intersects(obj->getSprite().getGlobalBounds());
}

void GameObj::play()
{
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.update(sf::Time(sf::seconds(0.05F)));
}
