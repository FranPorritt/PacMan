#include "Game.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"
#include "UI.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Update(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight)
{
	switch (currentState)
	{
	case gameState::Menu:
		Menu(window, screenWidth, screenHeight);
		break;

	case gameState::Playing:
		Play(window, screenWidth);
		break;

	case gameState::GameOver:
		GameOver(window, screenWidth);
		break;

	case gameState::GameWon:
		GameWon(window, screenWidth);
		break;

	case gameState::Restart:
		Restart(window);
		break;

	default:
		break;
	}
}

void Game::Menu(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight)
{
	sf::Clock clock;

	UI* ui = new UI();
	while (window.isOpen() && currentState == gameState::Menu)
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

		while (clock.getElapsedTime().asMilliseconds() < 100);
		clock.restart();

		ui->Menu(window, screenWidth, screenHeight);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			currentState = gameState::Playing;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			window.close();
		}

		window.display();
		window.clear();
	}
}

void Game::Play(sf::RenderWindow& window, const int& screenWidth)
{
	sf::Clock clock; // Find a better way, tick rate or something???
	srand(time(0));
	UI* ui = new UI();

	Map* map = new Map();
	map->FillMapPos();
	map->CreateMap(window);

	Points* points = Points::getInstance();

	playerSpawn = map->GetPlayerSpawn();
	Player* player = new Player(10.0f, sf::Color::Yellow, playerSpawn);

	ghosts.push_back(new Blinky(10.0f, sf::Color::Red, { 400.0f, 365.0f }, { 0,0 }));
	//blinky = ghosts[0];
	ghosts.push_back(new Pinky(10.0f, sf::Color(255, 182, 193), { 400.0f, 440.0f }, { 820,0 }));
	//ghosts.push_back(new Inky(10.0f, sf::Color::Cyan, { 350.0f, 440.0f }, { 0,960 }, blinky)); //BROKEN
	ghosts.push_back(new Clyde(10.0f, sf::Color(255, 69, 0), { 425.0f, 440.0f }, { 820,960 }));

	while (window.isOpen() && (currentState == gameState::Playing))
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
		while (clock.getElapsedTime().asMilliseconds() < 250);
		clock.restart();

		if (!isResetting)
		{
			map->Render(window);		// Renders walls and pellets
			map->Update();

			player->Update();
			player->Render(window);
			player->Move();

			// Player and wall/pellet collision checks
			currentPlayerPos = player->GetPlayerPos();
			map->CollisionChecks(currentPlayerPos);
			map->PelletCollisions(currentPlayerPos);
			player->SetCanMoveDown(map->GetWallBelow());
			player->SetCanMoveUp(map->GetWallAbove());
			player->SetCanMoveLeft(map->GetWallLeft());
			player->SetCanMoveRight(map->GetWallRight());

			for (Ghosts* ghost : ghosts)
			{

			/*	for (int ghostIndex = 0; ghostIndex < sizeof(ghosts); ghostIndex++)		// CAUSES HEAP CORRUPTION -- START OF STAGGERING LEAVING TIMES
				{
					if (behaviourTimer >= 0)
					{
						ghost[ghostIndex].LeaveHouse();
					}
				}*/

				// Collision Checks
				currentGhostPos = ghost->GetGhostPos();
				map->CollisionChecks(currentGhostPos);
				ghost->SetCanMoveDown(map->GetWallBelow());
				ghost->SetCanMoveUp(map->GetWallAbove());
				ghost->SetCanMoveLeft(map->GetWallLeft());
				ghost->SetCanMoveRight(map->GetWallRight());

				// If (ghosts is frightened) & (ghost isn't already frightened) & (ghost hasn't respawned)
				if (map->GetGhostsFright() && (!ghost->GetFright()) && (!ghost->GetRespawn()))
				{
					ghost->SetFrightenedTrue();
				}
				else if (!map->GetGhostsFright())
				{
					ghost->SetFrightenedFalse();
				}

				ghost->Update(currentPlayerPos, scatterTile);
				ghost->Render(window);

				ghost->PlayerCollision(currentPlayerPos); // Checks for collisions with player -- !!DOESN'T ALWAYS REGISTER OVERLAP!!
				if (ghost->GetPlayerDeath())
				{
					player->Respawn(playerSpawn); // If holding down when respawning, can get stuck in walls. FIX PLEASE
					for (Ghosts* ghost : ghosts)
					{
						ghost->Respawn();
						ghost->ResetBehaviour();
					}

					isResetting = true;
				}
			}
		}
		else
		{
			for (int i = 0; i < 10; i++) 
			{
				// Provides a 'loading screen' when player dies -- Helps prevent player getting stuck in walls
			}
			isResetting = false;
		}

		if (player->GetIsDead())
		{
			currentState = gameState::GameOver;
		}
		if (map->GetGameWon())
		{
			currentState = gameState::GameWon;
		}

		points->DisplayScore(window);
		player->DisplayLives(window);
		window.display();
		window.clear();
	}
}

void Game::GameOver(sf::RenderWindow& window, const int& screenWidth)
{
	UI* ui = new UI();

	while ((window.isOpen()) && (currentState == gameState::GameOver))
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

		// Displays text
		ui->GameOver(window, screenWidth);
		ui->GameEnd(window, screenWidth);
		//ui->HighScore(window, playerSnakeScore);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			currentState = gameState::Restart;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			window.close();
		}

		window.display();
		window.clear();
	}
}

void Game::GameWon(sf::RenderWindow& window, const int& screenWidth)
{
	UI* ui = new UI();

	while ((window.isOpen()) && (currentState == gameState::GameWon))
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

		// Displays text
		ui->GameEnd(window, screenWidth);
		ui->GameWon(window, screenWidth);
		//ui->HighScore(window, playerSnakeScore);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			currentState = gameState::Restart;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			window.close();
		}

		window.display();
		window.clear();
	}
}

void Game::Restart(sf::RenderWindow& window)
{
	window.display();
	window.clear();

	isRestarting = true;
}

bool Game::GetRestart()
{
	return isRestarting;
}
