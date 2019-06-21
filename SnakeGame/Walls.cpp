#include "Walls.h"

Walls::Walls(sf::Vector2f wallSizeArg, sf::Color wallColorArg) :
	wallSize(wallSizeArg), wallColor(wallColorArg)
{
}

Walls::~Walls()
{
}

void Walls::Render(sf::RenderWindow& window)
{
	sf::RectangleShape wall(wallSize);
	wall.setFillColor(wallColor);
	wall.setPosition(wallPos);
	window.draw(wall);
}

void Walls::SetPosition(sf::Vector2f& newWallPos)
{
	wallPos = newWallPos;
}

sf::Vector2f Walls::GetPosition()
{
	return wallPos;
}
