#pragma once
#include "BackgroundObj.h"

class BackgroundBlackHole :
	public BackgroundObj
{
public:
	BackgroundBlackHole(int randX, sf::Texture& texture);
	virtual ~BackgroundBlackHole();

	virtual void initAnimationFrames();
};

