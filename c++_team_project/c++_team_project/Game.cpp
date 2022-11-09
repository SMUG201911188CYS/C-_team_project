#include "Game.h"
#include "enum.h"

bool Game::game() {

	scene.show_StartIntro();
	scene.show_MainIntro();

	int main = room.intro();
	if (main == false) return false;

	scene.show_Scenario();

	scene.show_Sewer();
	room.sewer();

	scene.show_crossroads();
	room.crossroad();

	scene.show_room();

	if (room.Get_Sewer_in() == 1) { // C���� �ϼ���
		// ù��° ������
		if (room.Get_Crossroad_In(FIRST) == 1)  player_bag.input_item(room.c_room1_1());
		else if (room.Get_Crossroad_In(FIRST) == 2) player_bag.input_item(room.c_room1_2());
		else if (room.Get_Crossroad_In(FIRST) == 3) player_bag.input_item(room.c_room1_3());

		scene.show_crossroads();
		room.crossroad();

		//�ι�° ������
		scene.show_room();
		if (room.Get_Crossroad_In(FIRST) == 1)  player_bag.input_item(room.c_room2_1());
		else if (room.Get_Crossroad_In(FIRST) == 2) player_bag.input_item(room.c_room2_2());
		else if (room.Get_Crossroad_In(FIRST) == 3) player_bag.input_item(room.c_room2_3());


		scene.show_crossroads();
		room.crossroad();

		//����° ������
		scene.show_room();
		if (room.Get_Crossroad_In(FIRST) == 1)  player_bag.input_item(room.c_room_1());
		else if (room.Get_Crossroad_In(FIRST) == 2) player_bag.input_item(room.c_room1_2());
		else if (room.Get_Crossroad_In(FIRST) == 3) player_bag.input_item(room.c_room1_3());

	}
	else if (room.Get_Sewer_in() == 2) { // G417 �ϼ��� 
		if (room.Get_Crossroad_In(FIRST) == 1) player_bag.input_item(room.g_room1_1());
		else if (room.Get_Crossroad_In(FIRST) == 2) player_bag.input_item(room.g_room1_2());
		else if (room.Get_Crossroad_In(FIRST) == 3) player_bag.input_item(room.g_room1_3());
	}
	else if (room.Get_Sewer_in() == 3) { // �׳� �ϼ���
		if (room.Get_Crossroad_In(FIRST) == 1) player_bag.input_item(room.n_room1_1());
		else if (room.Get_Crossroad_In(FIRST) == 2) player_bag.input_item(room.n_room1_2());
		else if (room.Get_Crossroad_In(FIRST) == 3) player_bag.input_item(room.n_room1_3());
	}



}