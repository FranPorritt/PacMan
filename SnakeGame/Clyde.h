#pragma once
#include "Ghosts.h"

class Clyde : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 820,960 };

public:
	Clyde(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Clyde();
};

