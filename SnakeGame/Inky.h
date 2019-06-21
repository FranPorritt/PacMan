#pragma once
#include "Ghosts.h"

class Inky : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 0,960 };

public:
	Inky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Inky();
};

