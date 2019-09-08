#include "Points.h"

Points::Points()
{
}

Points* Points::instance = 0;

Points* Points::getInstance()
{
	if (instance == 0)
	{
		instance = new Points();
	}

	return instance;
}

void Points::AddPoints(int item)
{
	score += item;
}

void Points::DisplayScore(sf::RenderWindow& window)
{
	if (!font.loadFromFile("ka1.ttf"))
	{
		cout << "ERROR" << endl;
	}

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setPosition(10, 5);
	scoreText.setString("SCORE: " + to_string(score));
	scoreText.setFillColor(sf::Color::White);

	window.draw(scoreText);
}
