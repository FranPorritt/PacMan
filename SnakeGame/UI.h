#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class UI
{
protected:
	sf::Font font;

	//sf::Text scoreText;
	//sf::Text highScoreText;
	sf::Text restartText;
	sf::Text quitText;

	sf::Text loseText;
	sf::Text winText;

	sf::Text titleText;
	sf::Text startText;
	sf::Text quitMenuText;
	
	sf::Color fontColor = sf::Color::Red;

	//int highScore;
	//std::ofstream output;
	//std::ifstream input;

public:
	UI();
	~UI();

	// Displays consistent end game UI -- Score, restart, quit -- Used in conjunction with over/won functions
	void GameEnd(sf::RenderWindow& window, const int& screenWidth/*, int& playerSnakeScore*/);
	// Displays losing specific UI
	void GameOver(sf::RenderWindow& window, const int& screenWidth);
	// Displays winning specific UI
	void GameWon(sf::RenderWindow& window, const int& screenWidth);
	//void HighScore(sf::RenderWindow& window, int& playerSnakeScore);
	void Menu(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight);
};

