#include "Field.h"

void Field::NextStep()
{
	_turn++;

	ClearPrint();
	Print << _turn;
}

void Field::Draw(int size, Size offset) const
{
	for (auto y : step(_cells.height()))
	{
		for (auto x : step(_cells.width()))
		{
			Rect(x * size, y * size, size).movedBy(offset).drawFrame();
		}
	}

}