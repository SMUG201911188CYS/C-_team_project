#ifndef __GAME_H__

#define __GAME_H__

#include "enum.h"

class Game {
private:
	Control control;
	Scene scene;
	Ending end;
	Room room;
	Event event;
	Bag player_bag;
	Player dori_bear;
	Boss princess;
public:
	bool game();
	bool battle(bool do_battle);
	bool battle_check() {
		if (this->dori_bear.Get_Arms() == "����") return false;
		else return true;
	}
};

#endif // !__GAME_H__
