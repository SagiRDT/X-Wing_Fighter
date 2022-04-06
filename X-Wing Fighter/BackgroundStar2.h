#pragma once
#include "BackgroundObj.h"

class BackgroundStar2 :
	public BackgroundObj
{
public:
	BackgroundStar2(int randX, sf::Texture& texture);
	virtual ~BackgroundStar2();
	virtual void initAnimationFrames();
};

