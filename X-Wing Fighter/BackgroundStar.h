#pragma once
#include "BackgroundObj.h"

class BackgroundStar :
	public BackgroundObj
{
public:
	BackgroundStar(int randX, sf::Texture& texture);
	virtual ~BackgroundStar();
	virtual void initAnimationFrames();
};

