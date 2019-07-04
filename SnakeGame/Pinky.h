#pragma once
#include "Ghosts.h"

class Pinky : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 820,0 };
	sf::Vector2f lastPlayerPos;
	sf::Color activeColor = sf::Color(255, 182, 193);

public:
	Pinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Pinky();

	void Chase(sf::Vector2f& currentPlayerPos) override;
};

