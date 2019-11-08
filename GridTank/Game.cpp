#include "Game.h"

void Game::Update()
{
	for (auto& tank : _tanks)
	{
		tank.Think();
	}


	bool ready = _tanks.all([](Tank tank) { return tank.GetIsReady(); });
	if (ready)
	{
		for (auto& tank : _tanks)
		{
			tank.NextAction();

			// óÃàÊÇÃíÜÇ©ÇÁÇÕÇ›èoÇ≥Ç»Ç¢ÇÊÇ§Ç…Ç∑ÇÈ
			tank.Pos.x = Clamp(tank.Pos.x, 0, (int)_field.GetSize().x - 1);
			tank.Pos.y = Clamp(tank.Pos.y, 0, (int)_field.GetSize().y - 1);
		}
	}
}

void Game::Draw(int size, Size offset)
{
	_field.Draw(size, offset);

	for (auto& tank : _tanks)
	{
		// draw
		auto origin = tank.Pos * size + Point{ size, size } / 2;

		Circle(origin, size * 0.25)
			.movedBy(offset).draw(Palette::Gray);

		Vec2 dir = Vec2::Up().rotated(tank.Rad());
		Line(origin, origin + dir.setLength(size * 0.4))
			.movedBy(offset).draw(5, Palette::Lightgreen);
	}
}
