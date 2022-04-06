#pragma once
#include "GameObj.h"

class Obstacle :
	public GameObj
{
public:
	Obstacle();
	virtual ~Obstacle();

private:
	int m_hp;
	int m_worthPoints;
};

