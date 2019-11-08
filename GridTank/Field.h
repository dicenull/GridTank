#pragma once
#include "Tank.h"

class Field
{
public:
	Field();

	void NextStep();
	
	void Draw(int size, Size offset) const;

	Size GetSize() const { return Size(_cells.width(), _cells.height()); }

private:
	Grid<int> _cells;
	// TODO: s“®ˆ—‚ğGame‚ÉˆÚ‚·
	// Array<Tank> _tanks;
	// Array<Action> _actions;
	int _turn;
};
