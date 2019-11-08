
# include <Siv3D.hpp> // OpenSiv3D v0.4.1
#include "Field.h"

void Main()
{
	Field field;

	while (System::Update())
	{
		field.Draw(50, { 100, 10 });
		field.Update();

		if (KeyEnter.down())
		{
			field.NextStep();
		}
	}
}
