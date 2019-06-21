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

	// THIS NEEDS CHANGING -- WILL DETECT GHOSTS COLLISIONS TOO
	for (Pellets* p : pellets)
	{
		sf::Vector2f pelletPos = p->GetPosition();
		if (pelletPos == checkPos)
		{
			cout << "Collected Pellet" << endl;
			p->Collected();
			delete p;
		}
	}
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

sf::Vector2f Map::getBlinky()
{
	return blinkyScatterTile;
}

sf::Vector2f Map::getPinky()
{
	return pinkyScatterTile;
}

sf::Vector2f Map::getInky()
{
	return inkyScatterTile;
}

sf::Vector2f Map::getClyde()
{
	return clydeScatterTile;
}