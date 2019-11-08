#pragma once
#include <Siv3D.hpp>
#include "Action.hpp"

class Tank
{
public:
	Point Pos;
	int Direction;

	double Rad() const { return ToRadians(Direction); }

	Tank()
	{
		Pos = Point::Zero();
		Direction = 0;
	}

	void Think();

	bool GetIsReady() const { return _isReady; }

	void NextAction();

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
	Action _action;
	bool _isReady;
};
