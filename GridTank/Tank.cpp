#include "Tank.h"

void Tank::Think()
{
	if (_isReady) return;

	// TODO: —ñ‹“‚Ì‡”Ô‚ÅƒL[‚ğİ’è‚µ‚Ä‚¢‚é‚Ì‚Å’¼‚·
	Array<Key> keys = { KeyW, KeyS, KeyD, KeyA, KeySpace, KeyX };

	for (auto [i, key] : Indexed(keys))
	{
		if (key.down())
		{
			// tank.ActionBy((Action)i);
			_action = (Action)i;
			_isReady = true;
		}
	}
}

void Tank::NextAction()
{
	if (_isReady == false)
	{
		return;
	}
	_isReady = false;

	ActionBy(_action);
}
