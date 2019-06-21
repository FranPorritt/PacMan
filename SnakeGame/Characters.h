#pragma once

class Characters
{
protected:
	bool canMoveUp = false;
	bool canMoveDown = false;
	bool canMoveLeft = false;
	bool canMoveRight = false;

public:
	Characters();
	~Characters();

	void SetCanMoveUp(bool value);
	void SetCanMoveDown(bool value);
	void SetCanMoveLeft(bool value);
	void SetCanMoveRight(bool value);
};

