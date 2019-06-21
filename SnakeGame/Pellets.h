#pragma once
#include <SFML/Graphics.hpp>
#include "Points.h"

using namespace std;

class Pellets
{
protected:
	sf::CircleShape pellet;
	float pelletRadius = 5.0f;
	sf::Vector2f pelletPos;
	sf::Color pelletColor = sf::Color::White;

	Points* points = Points::getInstance();
	int pelletValue = 10;

public:
	Pellets(float pelletRadiusArg, sf::Color pelletColorArg);
	~Pellets();
	
	void Render(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f& newPelletPos);

	sf::Vector2f GetPosition();

	void Collected();
};

