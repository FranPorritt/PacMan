#pragma once
#include "Ghosts.h"

class Pinky : public Ghosts
{
public:
	Pinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Pinky();
};

