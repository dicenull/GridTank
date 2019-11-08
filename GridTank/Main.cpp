
# include <Siv3D.hpp> // OpenSiv3D v0.4.1
#include "Game.h"

void Main()
{
	Game game(Field(), { Tank(), Tank(Point(3, 3)), Tank(Point(7, 5)) });
	
	while (System::Update())
	{
		game.Update();
		game.Draw(50, { 100, 10 });
	}
}
