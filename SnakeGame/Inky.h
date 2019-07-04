#pragma once
#include "Ghosts.h"
#include "Blinky.h"

class Inky : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 0,960 };
	sf::Color activeColor = sf::Color::Cyan;

	Blinky& blinky;
	sf::Vector2f blinkyDistance;
	sf::Vector2f lastPlayerPos;

public:
	Inky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg, Blinky& blinky);
	~Inky();

	void Chase(sf::Vector2f& currentPlayerPos) override;
};

