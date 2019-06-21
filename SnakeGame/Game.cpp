#include "Game.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Update(sf::RenderWindow& window)
{
	switch (currentState)
	{
	case gameState::Playing:
		Play(window);
		break;

	case gameState::GameOver:
		break;

	default:
		break;
	}
}

void Game::Play(sf::RenderWindow& window)
{
	sf::Clock clock; // Find a better way, tick rate or something
	srand(time(0));

	Map* map = new Map();
	map->FillMapPos();
	map->CreateMap(window);

	Points* points = Points::getInstance();

	playerSpawn = map->GetPlayerSpawn();
	Player* player = new Player(10.0f, sf::Color::Yellow, playerSpawn);	

	//ghosts.push_back(new Blinky(10.0f, sf::Color::Red, { 275.0f, 365.0f }));
	/*ghosts.push_back(new Pinky(10.0f, sf::Color(255, 182, 193), { 400.0f, 440.0f }));
	ghosts.push_back(new Inky(10.0f, sf::Color::Cyan, { 350.0f, 440.0f }));
	ghosts.push_back(new Clyde(10.0f, sf::Color(255, 69, 0), { 450.0f, 440.0f }));*/

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
		while (clock.getElapsedTime().asMilliseconds() < 200);
		clock.restart();

		map->Render(window);
		player->Render(window);
		player->Move();

		// Player collision checks
		currentPlayerPos = player->GetPlayerPos();
		map->CollisionChecks(currentPlayerPos);
		player->SetCanMoveDown(map->GetWallBelow());
		player->SetCanMoveUp(map->GetWallAbove());
		player->SetCanMoveLeft(map->GetWallLeft());
		player->SetCanMoveRight(map->GetWallRight());

		for (Ghosts* ghost : ghosts)
		{		
			// Collision Checks
			currentGhostPos = ghost->GetGhostPos();
			map->CollisionChecks(currentGhostPos);
			ghost->SetCanMoveDown(map->GetWallBelow());
			ghost->SetCanMoveUp(map->GetWallAbove());
			ghost->SetCanMoveLeft(map->GetWallLeft());
			ghost->SetCanMoveRight(map->GetWallRight());
			
			if (behaviourTimer < 100)
			{
				ghost->Chase(currentPlayerPos);	
			}
			else
			{
				ghost->Scatter(TESTTARGET);
			}
			ghost->Pathfinding();
			ghost->Move();	
			ghost->Render(window);		
		}
		
		if (behaviourTimer > 150)
		{
			behaviourTimer = 0;
		}
		behaviourTimer++;

		points->DisplayScore(window);
		window.display();
		window.clear();
	}

}
