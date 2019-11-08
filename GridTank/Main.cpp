
# include <Siv3D.hpp> // OpenSiv3D v0.4.1
#include "Game.h"

void Main()
{
	Game game(Field(), { Tank() });
	
	while (System::Update())
	{
		game.Update();
		game.Draw(50, { 100, 10 });
	}
}
