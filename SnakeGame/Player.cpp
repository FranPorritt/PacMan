#include "Player.h"

Player::Player(float playerRadiusArg, sf::Color playerColorArg, sf::Vector2f playerPosArg) :
	playerRadius(playerRadiusArg), playerColor(playerColorArg), playerPos(playerPosArg)
{
}

Player::~Player()
{
}

void Player::Render(sf::RenderWindow& window)
{
	sf::CircleShape player(playerRadius);
	player.setOrigin(-2.5, -2.5);
	player.setPosition(playerPos);
	player.setFillColor(playerColor);
	window.draw(player);
}

void Player::SetPosition(sf::Vector2f& newPlayerPos)
{
	playerPos = newPlayerPos;
}

void Player::Move()
{
	if (((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) && (canMoveUp))
	{
		direction = EDirection::eUp;
	}
	else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) && (canMoveDown))
	{
		direction = EDirection::eDown;
	}
	else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) && (canMoveLeft))
	{
		direction = EDirection::eLeft;
	}
	else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) && (canMoveRight))
	{
		direction = EDirection::eRight;
	}
	/*else if (isDead)
	{
		direction = EDirection::eStop;
	}*/

	if ((!canMoveUp) && (direction == EDirection::eUp))
	{
		direction = EDirection::eStop;
	}
	if ((!canMoveDown) && (direction == EDirection::eDown))
	{
		direction = EDirection::eStop;
	}
	if ((!canMoveLeft) && (direction == EDirection::eLeft))
	{
		direction = EDirection::eStop;
	}
	if ((!canMoveRight) && (direction == EDirection::eRight))
	{
		direction = EDirection::eStop;
	}

	switch (direction)
	{
	case EDirection::eUp:
		playerPos.y -= gridSize;
		break;

	case EDirection::eDown:
		playerPos.y += gridSize;
		break;

	case EDirection::eRight:
		playerPos.x += gridSize;
		break;

	case EDirection::eLeft:
		playerPos.x -= gridSize;
		break;

	case EDirection::eStop:
		break;

	default:
		break;
	}
}

sf::Vector2f Player::GetPlayerPos()
{
	return playerPos;
}
