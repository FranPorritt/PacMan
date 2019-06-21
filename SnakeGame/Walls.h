#pragma once
#include <SFML/Graphics.hpp>

class Walls
{
protected:
	sf::RectangleShape wall;
	sf::Vector2f wallSize = { 20.0f, 20.0f };
	sf::Vector2f wallPos;
	sf::Color wallColor = sf::Color::Blue;

public:
	Walls(sf::Vector2f wallSizeArg, sf::Color wallColorArg);
	~Walls();

	void Render(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f& newWallPos);

	sf::Vector2f GetPosition();
};

