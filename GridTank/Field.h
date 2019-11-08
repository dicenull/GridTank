#pragma once
#include "Tank.h"

class Field
{
public:
	Field() : _cells(Grid<int>(10, 10)), _turn(0) {};

	Field(Size size) : _cells(Grid<int>(size.x, size.y)), _turn(0) {};

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
