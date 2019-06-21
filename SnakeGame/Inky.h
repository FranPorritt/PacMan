#pragma once
#include "Ghosts.h"

class Inky : public Ghosts
{
public:
	Inky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Inky();
};

