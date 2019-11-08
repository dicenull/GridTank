#include "Field.h"

Field::Field()
{
	_field = Grid<int>(10, 10);
	_tanks.push_back(Tank());
	_turn = 0;

	for (auto i : step(_tanks.size()))
	{
		_actions.push_back(Action::Stop);
	}
}

void Field::NextStep()
{
	for (auto i = 0; i < _tanks.size(); i++)
	{
		_tanks[i].ActionBy(_actions[i]);
	}

	// —Ìˆæ‚Ì’†‚©‚ç‚Í‚Ýo‚³‚È‚¢‚æ‚¤‚É‚·‚é
	for (auto& tank : _tanks)
	{
		tank.Pos.x = Clamp(tank.Pos.x, 0, (int)_field.width() - 1);
		tank.Pos.y = Clamp(tank.Pos.y, 0, (int)_field.height() - 1);
	}

	_turn++;

	ClearPrint();
	Print << _turn;
}

void Field::Update()
{
	for (auto& action : _actions)
	{
		// update
		// TODO: —ñ‹“‚Ì‡”Ô‚ÅƒL[‚ðÝ’è‚µ‚Ä‚¢‚é‚Ì‚Å’¼‚·
		Array<Key> keys = { KeyW, KeyS, KeyD, KeyA, KeySpace, KeyX };

		for (auto [i, key] : Indexed(keys))
		{
			if (key.down())
			{
				// tank.ActionBy((Action)i);
				action = (Action)i;
			}
		}
	}
}

void Field::Draw(int size, Size offset) const
{
	for (auto y : step(_field.height()))
	{
		for (auto x : step(_field.width()))
		{
			Rect(x * size, y * size, size).movedBy(offset).drawFrame();
		}
	}

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