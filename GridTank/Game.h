#pragma once
#include <Siv3D.hpp>
#include "Field.h"

class Game
{
public:
	Game(Field field, Array<Tank> tanks)
		: _field(field), _tanks(tanks) {}

public:
	void Update();

	void Draw(int size, Size offset);

private:
	Field _field;
	Array<Tank> _tanks;
};

