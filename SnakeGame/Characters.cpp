#include "Characters.h"

Characters::Characters()
{
}

Characters::~Characters()
{
}

void Characters::SetCanMoveUp(bool value)
{
	value ? (canMoveUp = false) : (canMoveUp = true);
}

void Characters::SetCanMoveDown(bool value)
{
	value ? (canMoveDown = false) : (canMoveDown = true);
}

void Characters::SetCanMoveLeft(bool value)
{
	value ? (canMoveLeft = false) : (canMoveLeft = true);
}

void Characters::SetCanMoveRight(bool value)
{
	value ? (canMoveRight = false) : (canMoveRight = true);
}
