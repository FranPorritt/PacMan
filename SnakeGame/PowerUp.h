#pragma once
#include <SFML/Graphics.hpp>
#include "Points.h"

class PowerUp
{
protected:
	sf::CircleShape powerUp;
	float powerRadius = 8.0f;
	sf::Vector2f powerPos;
	sf::Color powerColor = sf::Color::White;

	bool powerUpActive = false;

	Points* points = Points::getInstance();
	int powerValue = 50;

public:
	PowerUp(float powerRadiusArg, sf::Color powerColorArg);
	~PowerUp();

	void Render(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f& newPowerPos);

	sf::Vector2f GetPosition();
	bool GetPower();

	void Collected();
};

