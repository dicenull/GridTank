#pragma once
#include "Tank.h"

class Field
{
public:
	Field();
	

	void NextStep();
	

	void Update();
	

	void Draw(int size, Size offset) const;
	

private:
	Grid<int> _field;
	Array<Tank> _tanks;
	Array<Action> _actions;
	int _turn;
};
