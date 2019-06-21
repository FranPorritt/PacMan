#pragma once
#include "Ghosts.h"

class Blinky : public Ghosts
{
public:
	Blinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Blinky();
};

