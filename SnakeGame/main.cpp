#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(820, 960), "Pac Man: Francesca Porritt");
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

		game->Update(window);

		window.display();
	}

	std::cout << "PacMan: Finished" << std::endl;

	return 0;
}
