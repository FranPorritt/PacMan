#pragma once
#include "Ghosts.h"

class Clyde : public Ghosts
{
public:
	Clyde(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Clyde();
};

