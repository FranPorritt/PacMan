#include "Pellets.h"

Pellets::Pellets(float pelletRadiusArg, sf::Color pelletColorArg) :
	pelletRadius(pelletRadiusArg), pelletColor(pelletColorArg)
{
}

Pellets::~Pellets()
{
}

void Pellets::Render(sf::RenderWindow& window)
{
	sf::CircleShape pellet(pelletRadius);		// EXCEPTION BEING THROWN
	pellet.setOrigin(-7.5, -7.5);
	pellet.setPosition(pelletPos);
	pellet.setFillColor(pelletColor);
	window.draw(pellet);
}

void Pellets::SetPosition(sf::Vector2f& newPelletPos)
{
	pelletPos = newPelletPos;
}

sf::Vector2f Pellets::GetPosition()
{
	return pelletPos;
}

void Pellets::Collected()
{
	points->AddPoints(pelletValue);
}