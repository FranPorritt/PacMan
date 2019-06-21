#pragma once
#include "Ghosts.h"

class Pinky : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 820,0 };

public:
	Pinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Pinky();
};

