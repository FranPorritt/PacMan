#include "UI.h"
#include <iostream>

UI::UI()
{
}

UI::~UI()
{
}

void UI::GameEnd(sf::RenderWindow& window, const int& screenWidth/*, int& playerScore*/)
{
	if (!font.loadFromFile("ka1.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
	// Score Text
	/*scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setPosition(500, 250);
	scoreText.setString("SCORE: " + std::to_string(playerScore));
	scoreText.setFillColor(fontColor);
	scoreText.setOrigin(floor(scoreText.getLocalBounds().width / 2), floor(scoreText.getLocalBounds().height / 2));*/

	// Restart Text
	restartText.setFont(font);
	restartText.setCharacterSize(35);
	restartText.setPosition(screenWidth / 2, 600);
	restartText.setString("PRESS SPACE TO RESTART");
	restartText.setFillColor(fontColor);
	restartText.setOrigin(floor(restartText.getLocalBounds().width / 2), floor(restartText.getLocalBounds().height / 2));

	// Quit Text
	quitText.setFont(font);
	quitText.setCharacterSize(35);
	quitText.setPosition(screenWidth / 2, 700);
	quitText.setString("PRESS Q TO QUIT");
	quitText.setFillColor(fontColor);
	quitText.setOrigin(floor(quitText.getLocalBounds().width / 2), floor(quitText.getLocalBounds().height / 2));

	// Render
	//window.draw(scoreText);
	window.draw(restartText);
	window.draw(quitText);
}

void UI::GameOver(sf::RenderWindow& window, const int& screenWidth)
{
	if (!font.loadFromFile("ka1.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}

	// Lose Text
	loseText.setFont(font);
	loseText.setCharacterSize(50);
	loseText.setPosition(screenWidth / 2, 100);
	loseText.setString("GAME OVER");
	loseText.setFillColor(fontColor);
	loseText.setOrigin(floor(loseText.getLocalBounds().width / 2), floor(loseText.getLocalBounds().height / 2));

	window.draw(loseText);
}

void UI::GameWon(sf::RenderWindow& window, const int& screenWidth)
{
	if (!font.loadFromFile("ka1.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}

	// Win Text
	winText.setFont(font);
	winText.setCharacterSize(50);
	winText.setPosition(screenWidth / 2, 100);
	winText.setString("YOU WON");
	winText.setFillColor(fontColor);
	winText.setOrigin(floor(winText.getLocalBounds().width / 2), floor(winText.getLocalBounds().height / 2));

	window.draw(winText);
}

//void UI::HighScore(sf::RenderWindow& window, int& playerSnakeScore)
//{
//	input.open("highScore.txt.");
//	if (output.fail())
//	{
//		std::cerr << "Could not open file for write" << std::endl;
//	}
//	input >> highScore;
//	input.close();
//
//	if (highScore < playerSnakeScore)
//	{
//		output.open("highScore.txt");
//		if (output.fail())
//		{
//			std::cerr << "Could not open file for write" << std::endl;
//		}
//		output << playerSnakeScore << std::endl;
//		output.close();
//	}
//
//	if (!font.loadFromFile("ka1.ttf"))
//	{
//		std::cout << "ERROR" << std::endl;
//	}
//
//	// High Score Text
//	highScoreText.setFont(font);
//	highScoreText.setCharacterSize(50);
//	highScoreText.setPosition(500, 350);
//	highScoreText.setString("HIGH SCORE: " + std::to_string(highScore));
//	highScoreText.setFillColor(sf::Color::Red);
//	highScoreText.setOrigin(floor(highScoreText.getLocalBounds().width / 2), floor(highScoreText.getLocalBounds().height / 2));
//
//	window.draw(highScoreText);
//}

void UI::Menu(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight)
{
	if (!font.loadFromFile("ka1.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}

	titleText.setFont(font);
	titleText.setCharacterSize(75);
	titleText.setPosition(screenWidth / 2, screenHeight / 6);
	titleText.setString("PAC-MAN");
	titleText.setFillColor(sf::Color::Yellow);
	titleText.setOrigin(floor(titleText.getLocalBounds().width / 2), floor(titleText.getLocalBounds().height / 2));

	// Start Text
	startText.setFont(font);
	startText.setCharacterSize(35);
	startText.setPosition(screenWidth / 2, 650);
	startText.setString("PRESS SPACE TO START");
	startText.setFillColor(fontColor);
	startText.setOrigin(floor(startText.getLocalBounds().width / 2), floor(startText.getLocalBounds().height / 2));

	// Quit text
	quitMenuText.setFont(font);
	quitMenuText.setCharacterSize(35);
	quitMenuText.setPosition(screenWidth / 2, 750);
	quitMenuText.setString("PRESS Q TO QUIT");
	quitMenuText.setFillColor(fontColor);
	quitMenuText.setOrigin(floor(quitMenuText.getLocalBounds().width / 2), floor(quitMenuText.getLocalBounds().height / 2));


	// Render
	window.draw(titleText);
	window.draw(startText);
	window.draw(quitMenuText);
}