#include <iostream>
#include <SFML/Graphics.hpp>
#include<time.h> 
#include "Game.h"

int main()
{
	srand(time(0));
	const int screenWidth = 820;
	const int screenHeight = 960;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Pac Man: Francesca Porritt");
	std::cout << "PacMan: Starting" << std::endl;

	Game* game = new Game();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear();

		game->Update(window, screenWidth, screenHeight);

		if (game->GetRestart())
		{
			game = new Game();
		}

		window.display();
	}

	std::cout << "PacMan: Finished" << std::endl;

	delete game;

	return 0;
}
