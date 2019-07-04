#include "PowerUp.h"

PowerUp::PowerUp(float powerRadiusArg, sf::Color powerColorArg) :
	powerRadius(powerRadiusArg), powerColor(powerColorArg)
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::Render(sf::RenderWindow& window)
{
	sf::CircleShape powerUp(powerRadius);
	powerUp.setOrigin(-5, -5);
	powerUp.setPosition(powerPos);
	powerUp.setFillColor(powerColor);
	window.draw(powerUp);
}

void PowerUp::SetPosition(sf::Vector2f & newPowerPos)
{
	powerPos = newPowerPos;
}

sf::Vector2f PowerUp::GetPosition()
{
	return powerPos;
}

bool PowerUp::GetPower()
{
	return powerUpActive;
}

void PowerUp::Collected()
{
	powerUpActive = true;
	points->AddPoints(powerValue);
}

