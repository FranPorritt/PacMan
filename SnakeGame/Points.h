#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Points
{
private:
	static Points* instance;
	Points();

public:
	static Points* getInstance();

	void AddPoints(int item);
	int score = 0;

	void DisplayScore(sf::RenderWindow& window);
};

