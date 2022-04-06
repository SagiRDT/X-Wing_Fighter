#include "Button.h"
#include "Menu.h"
#include <string>

//Button builder
Button::Button(sf::Vector2f position, std::string pathToTexture)
{
	//load texture
	if(!m_texture.loadFromFile(pathToTexture))
		exit(EXIT_FAILURE);

	//set the textures into the sprites, set the sprites position
	m_animationRegular.setSpriteSheet(m_texture);
	m_animationMouseOver.setSpriteSheet(m_texture);
	
	m_animatedSprite = AnimatedSprite(sf::seconds(0.2F));
	m_animatedSprite.setPosition(position);
	m_currentAnimation = &m_animationRegular;
}

//Button destructor
Button::~Button()
{
}

//Change the button sprite depends on mouse over or not
void Button::setAnimation(bool isMouseOver)
{
	if (isMouseOver)
	{
		m_currentAnimation = &m_animationMouseOver;
	}
	else
	{
		m_currentAnimation = &m_animationRegular;
	}
}


//checking if a button was clicked/moved on with mouse - return true if it was, else return flase
bool Button::checkCoords(sf::RenderWindow& window, sf::Vector2f& coords)
{
	return (m_animatedSprite.getGlobalBounds().contains(coords));
}

//Play the animation of the button
void Button::play()
{
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.update(sf::Time(sf::seconds(0.05F)));
}