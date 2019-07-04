#include "Map.h"
#include <iostream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::FillMapPos() // Fills array with grid positions
{
	for (int xIndex = 0; xIndex < rows; xIndex++)
	{
		for (int yIndex = 0; yIndex < cols; yIndex++)
		{
			mapPos[xIndex][yIndex] = { x, y };
			x += gridSize; 
		}
		x = 0.0f;
		y += gridSize;
	}
}

void Map::CreateMap(sf::RenderWindow& window)
{
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int colIndex = 0; colIndex < cols; colIndex++)
		{
			if (grid[rowIndex][colIndex] == 1) // Finds wall spaces on grid and creates a new instance of the wall class
			{
				Walls* wall = new Walls({ gridSize,gridSize }, sf::Color::Blue);
				newWallPos = (mapPos[rowIndex][colIndex]);
				wall->SetPosition(newWallPos); // Passes map position to wall
				walls.push_back(wall);
			}
			else if (grid[rowIndex][colIndex] == 0) // Finds pellet spaces on grid and creates a new instance of the pellet class
			{
				Pellets* pellet = new Pellets(5.0f, sf::Color::White);
				newPelletPos = (mapPos[rowIndex][colIndex]);
				pellet->SetPosition(newPelletPos); // Passes map position to pellet
				pellets.push_back(pellet);
			}
			else if (grid[rowIndex][colIndex] == 4) // Finds power up spaces on grid and creates a new instance of the power up class
			{
				PowerUp* powerUp = new PowerUp(8.0f, sf::Color::White);
				newPowerPos = (mapPos[rowIndex][colIndex]);
				powerUp->SetPosition(newPowerPos); // Passes map position to powerUp
				powerUps.push_back(powerUp);
			}
		}
	}
}

sf::Vector2f Map::GetPlayerSpawn()
{
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int colIndex = 0; colIndex < cols; colIndex++)
		{
			if (grid[rowIndex][colIndex] == 3) // Finds player spawn and creates new instance of player class
			{
				playerSpawn = (mapPos[rowIndex][colIndex]);
			}
		}
	}

	return playerSpawn;
}

void Map::Render(sf::RenderWindow& window)
{
	for (Walls* w : walls)
	{
		w->Render(window);
	}

	for (Pellets* p : pellets)
	{
		p->Render(window);
	}

	for (PowerUp* powerUp : powerUps)
	{
		powerUp->Render(window);
	}
}

void Map::Update()
{
	if (areGhostsFrightened)
	{
		GhostsFrightened();
	}
}

void Map::CollisionChecks(sf::Vector2f& checkPos)
{
	wallBelow = false;
	wallAbove = false;
	wallLeft = false;
	wallRight = false;

	for (Walls* w : walls)
	{
		sf::Vector2f wallPos = w->GetPosition();
		if (wallPos.x == checkPos.x && wallPos.y == checkPos.y + gridSize)
		{
			wallBelow = true;
		}	

		if (wallPos.x == checkPos.x && wallPos.y == checkPos.y - gridSize)
		{
			wallAbove = true;
		}

		if (wallPos.y == checkPos.y && wallPos.x == checkPos.x + gridSize)
		{
			wallRight = true;
		}

		if (wallPos.y == checkPos.y && wallPos.x == checkPos.x - gridSize)
		{
			wallLeft = true;
		}
	}	
}

void Map::PelletCollisions(sf::Vector2f& checkPos)
{
	for (Pellets* p : pellets)
	{
		sf::Vector2f pelletPos = p->GetPosition();
		if (pelletPos == checkPos)
		{
			p->Collected();
			delete p;
		}
	}

	for (PowerUp* powerUp : powerUps)
	{
		sf::Vector2f powerPos = powerUp->GetPosition();
		if (powerPos == checkPos)
		{
			cout << "Collected POWER UP" << endl;	

			areGhostsFrightened = true;
			frightTimer = 0;	// Resets fright timer in case it's already active

			powerUp->Collected();
			delete powerUp;
		}
	}
}

void Map::GhostsFrightened()
{
	if (frightTimer >= frightTime)
	{
		areGhostsFrightened = false;
		frightTimer = 0;
	}
	else
	{
		areGhostsFrightened = true;
	}

	frightTimer++;
}

bool Map::GetWallAbove()
{
	return wallAbove;
}

bool Map::GetWallBelow()
{
	return wallBelow;
}

bool Map::GetWallLeft()
{
	return wallLeft;
}

bool Map::GetWallRight()
{
	return wallRight;
}

bool Map::GetGhostsFright()
{
	return areGhostsFrightened;
}