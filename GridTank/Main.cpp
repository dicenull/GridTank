
# include <Siv3D.hpp> // OpenSiv3D v0.4.1

enum class Action
{
	MoveForward,
	MoveBackward,
	TurnRight,
	TurnLeft,
	Shot,
	Stop,
};

class Tank
{
public:
	Point Pos;
	int Direction;

	double Rad() { return ToRadians(Direction); }

	Tank()
	{
		Pos = Point::Zero();
		Direction = 0;
	}

public:
	void ActionBy(Action action)
	{
		switch (action)
		{
		case Action::MoveForward:
			moveForward();
			break;
		case Action::MoveBackward:
			moveBackward();
			break;
		case Action::Shot:
			shot();
			break;
		case Action::Stop:
			break;
		case Action::TurnRight:
			turnRight();
			break;
		case Action::TurnLeft:
			turnLeft();
			break;
		default:
			break;
		}

		_validBack = (action == Action::Stop);
	}

private:
	void move(Vec2 origin)
	{
		Pos += Round(origin.rotated(Rad())).asPoint();
	}

	void moveForward()
	{
		move(Vec2::Up());
	}

	void shot()
	{
		// TODO: 弾を撃てるようにする. インターバルを設ける
	}

	void moveBackward()
	{
		if (!_validBack)
		{
			return;
		}

		move(Vec2::Down());
	}

	void turnRight() 
	{
		Direction = (Direction + 45) % 360;
	}

	void turnLeft() 
	{
		Direction = (Direction + 360 - 45) % 360;
	}
private:
	bool _validBack;
};

class Field
{
public:
	Field()
	{
		_field = Grid<int>(10, 10);
		_tanks.push_back(Tank());
	}

	void Draw(int size, Size offset)
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

		for(auto& tank : _tanks)
		{
			// update
			// TODO: 列挙の順番でキーを設定しているので直す
			Array<Key> keys = { KeyW, KeyS, KeyD, KeyA, KeySpace, KeyX };

			for (auto [i, key] : Indexed(keys))
			{
				if (key.down())
				{
					tank.ActionBy((Action)i);
				}
			}
		}
	}

private:
	Grid<int> _field;
	Array<Tank> _tanks;
};

void Main()
{
	Field field;

	while (System::Update())
	{
		field.Draw(50, { 100, 10 });
	}
}
