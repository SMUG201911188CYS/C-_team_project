#include "Game.h"
#include "enum.h"

bool Game::game() {

	int what_Event = NONE;
	int get_1 = NONE;
	int get_2 = NONE;
	int get_3 = NONE;

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
		if (room.Get_Crossroad_In(FIRST) == 1) what_Event = room.c_room1_1(); // �׾Ƹ�, ����, ������
		else if (room.Get_Crossroad_In(FIRST) == 2) what_Event = room.c_room1_2(); // ��������, �׾Ƹ�, ������
		else if (room.Get_Crossroad_In(FIRST) == 3) what_Event = room.c_room1_3(); // ��������, ����, �׾Ƹ�

		// �̺�Ʈ ó��
		if (what_Event == pot) get_1 = event.pot();
		else if (what_Event == box) get_1 = event.box();
		else if (what_Event == paper) get_1 = event.paper();
		else if (what_Event == hole) get_1 = event.hole();
		else get_1 = NONE;


		scene.show_crossroads();
		room.crossroad();

		//�ι�° ������
		scene.show_room();
		if (room.Get_Crossroad_In(SECOND) == 1) what_Event = room.c_room2_1();  // �̻��� ���, å��, �׾Ƹ�
		else if (room.Get_Crossroad_In(SECOND) == 2) what_Event = room.c_room2_2(); // ����, å��, �׾Ƹ�
		else if (room.Get_Crossroad_In(SECOND) == 3) what_Event = room.c_room2_3(); // ������

		// �̺�Ʈ ó��
		if (what_Event == pot) get_2 = event.pot();
		else if (what_Event == npc) get_2 = event.npc(room.Get_Sewer_in());
		else if (what_Event == bookshelf) get_2 = event.bookshelf();
		else if (what_Event == hole) get_2 = event.hole();
		else get_2 = NONE;

		scene.show_crossroads();
		room.crossroad();

		//����° ������
		scene.show_room();
		if (room.Get_Crossroad_In(THIRD) == 1) what_Event = room.c_room3_1(); // ������, �㱸��, �׾Ƹ�
		else if (room.Get_Crossroad_In(THIRD) == 2) what_Event = room.c_room3_2();// ���ι�, �㱸��, �׾Ƹ�
		else if (room.Get_Crossroad_In(THIRD) == 3) what_Event = room.c_room3_3(); // ��������, ������, �׾Ƹ�

		// �̺�Ʈ ó��
		if (what_Event == pot) get_3 = event.pot();
		else if (what_Event == pipe) get_3 = event.pipe(room.Get_Sewer_in());
		else if (what_Event == lake) get_3 = event.lake(room.Get_Sewer_in());
		else if (what_Event == paper) get_3 = event.paper();
		else if (what_Event == mouse) get_3 = event.mouse();
		else if (what_Event == hole) get_3 = event.hole();
		else get_1 = NONE;

	}
	else if (room.Get_Sewer_in() == 2) { // G417 �ϼ��� 

		if (room.Get_Crossroad_In(FIRST) == 1) what_Event = room.g_room1_1(); // ����, ������, ��������
		else if (room.Get_Crossroad_In(FIRST) == 2) what_Event = room.g_room1_2(); // �㱸��, �׾Ƹ�, ������
		else if (room.Get_Crossroad_In(FIRST) == 3) what_Event = room.g_room1_3(); // ������

		// �̺�Ʈ ó��
		if (what_Event == pot) get_1 = event.pot();
		else if (what_Event == box) get_1 = event.box();
		else if (what_Event == paper) get_1 = event.paper();
		else if (what_Event == hole) get_1 = event.hole();
		else if (what_Event == mouse) get_1 = event.mouse();
		else get_1 = NONE;

		scene.show_crossroads();
		room.crossroad();

		//�ι�° ������
		scene.show_room();

		if (room.Get_Crossroad_In(SECOND) == 1) what_Event = room.g_room2_1(); // �̻��� ��, ����, ������
		else if (room.Get_Crossroad_In(SECOND) == 2) what_Event = room.g_room2_2(); // �̻��� ���, �׾Ƹ�, ����
		else if (room.Get_Crossroad_In(SECOND) == 3) what_Event = room.g_room2_3(); // �̻��� ���, �̻��� ��, ������

		// �̺�Ʈ ó��
		if (what_Event == pot) get_2 = event.pot();
		else if (what_Event == npc) get_2 = event.npc(room.Get_Sewer_in());
		else if (what_Event == circle) get_2 = event.circle();
		else if (what_Event == box) get_2 = event.box();
		else if (what_Event == hole) get_2 = event.hole();
		else get_2 = NONE;

		scene.show_crossroads();
		room.crossroad();

		//����° ������
		scene.show_room();

		if (room.Get_Crossroad_In(THIRD) == 1) what_Event = room.g_room3_1(); // ������, �㱸��, ������
		else if (room.Get_Crossroad_In(THIRD) == 2) what_Event = room.g_room3_2(); // ���ι�, �㱸��, ����
		else if (room.Get_Crossroad_In(THIRD) == 3) what_Event = room.g_room3_3(); // ��������, ������, �׾Ƹ�

		// �̺�Ʈ ó��
		if (what_Event == pot) get_3 = event.pot();
		else if (what_Event == pipe) get_3 = event.pipe(room.Get_Sewer_in());
		else if (what_Event == lake) get_3 = event.lake(room.Get_Sewer_in());
		else if (what_Event == paper) get_3 = event.paper();
		else if (what_Event == mouse) get_3 = event.mouse();
		else if (what_Event == box) get_3 = event.box();
		else if (what_Event == hole) get_3 = event.hole();
		else get_1 = NONE;

	}
	else if (room.Get_Sewer_in() == 3) { // �׳� �ϼ���

		if (room.Get_Crossroad_In(FIRST) == 1) what_Event = room.n_room1_1(); // ��������, ����, ������
		else if (room.Get_Crossroad_In(FIRST) == 2) what_Event = room.n_room1_2(); // �㱸��, �׾Ƹ�, ������
		else if (room.Get_Crossroad_In(FIRST) == 3) what_Event = room.n_room1_3(); // ����, ������, �׾Ƹ�

		// �̺�Ʈ ó��
		if (what_Event == pot) get_1 = event.pot();
		else if (what_Event == box) get_1 = event.box();
		else if (what_Event == paper) get_1 = event.paper();
		else if (what_Event == hole) get_1 = event.hole();
		else if (what_Event == mouse) get_1 = event.mouse();
		else get_1 = NONE;

		scene.show_crossroads();
		room.crossroad();

		//�ι�° ������
		scene.show_room();

		if (room.Get_Crossroad_In(SECOND) == 1) what_Event = room.n_room2_1(); // ����ġ, ������, �̻��� ���
		else if (room.Get_Crossroad_In(SECOND) == 2) what_Event = room.n_room2_2(); // ����, ����ġ, ��������
		else if (room.Get_Crossroad_In(SECOND) == 3) what_Event = room.n_room2_3(); // ������

		// �̺�Ʈ ó��
		if (what_Event == npc) get_2 = event.npc(room.Get_Sewer_in());
		else if (what_Event == box) get_2 = event.box();
		else if (what_Event == paper) get_2 = event.paper();
		else if (what_Event == hole) get_2 = event.hole();
		else if (what_Event == button) get_2 = event.button();
		else get_2 = NONE;


		scene.show_crossroads();
		room.crossroad();

		//����° ������
		scene.show_room();

		if (room.Get_Crossroad_In(THIRD) == 1) what_Event = room.n_room3_1(); // ������, �㱸��, ����
		else if (room.Get_Crossroad_In(THIRD) == 2) what_Event = room.n_room3_2(); // ���ι�, �㱸��, ������
		else if (room.Get_Crossroad_In(THIRD) == 3) what_Event = room.n_room3_3(); // �㱸��, ������, �׾Ƹ�

		// �̺�Ʈ ó��
		if (what_Event == pot) get_3 = event.pot();
		else if (what_Event == pipe) get_3 = event.pipe(room.Get_Sewer_in());
		else if (what_Event == lake) get_3 = event.lake(room.Get_Sewer_in());
		else if (what_Event == mouse) get_3 = event.mouse();
		else if (what_Event == box) get_3 = event.box();
		else if (what_Event == hole) get_3 = event.hole();
		else get_1 = NONE;

	}

	// 1�������� ������Ʈ ��� : �׾Ƹ�, ����, ��������, �㱸��, ������
	
	if (get_1 == GET_CHEESE) dori_bear.Set_Shield(dori_bear.Get_Shield() + CHEESE_SHIELD);
	else if (get_1 == NONE) std::cout << "";
	else player_bag.input_item(get_1);

	
	// 2�������� ������Ʈ ��� : �̻��� ���, å��, �׾Ƹ�, ����, ������, �̻��� ��, ����ġ

	if (get_2 == GET_DEADHARD) dori_bear.Set_Passive(DEADHARD);
	else if (get_2 == GET_FARMING) dori_bear.Set_Passive(FARMING);
	else if (get_2 == NONE) std::cout << "";
	else player_bag.input_item(get_2);

	// 3�������� ������Ʈ ��� : ������, �㱸��, �׾Ƹ�, ���ι�, ��������, ������, ����

	if (get_3 == GET_CHEESE) dori_bear.Set_Shield(dori_bear.Get_Shield() + CHEESE_SHIELD);
	else if (get_3 == GET_Wings) dori_bear.Set_Arms(Wings);
	else if (get_3 == GET_CatArms) dori_bear.Set_Arms(CatArms);
	else if (get_3 == GET_DoriArms) dori_bear.Set_Arms(Dori_Bear_arms);
	else if (get_3 == GET_Twigs) dori_bear.Set_Arms(Twigs);
	else if (get_3 == GET_BarbieArms) dori_bear.Set_Arms(BarbieArms);
	else if (get_3 == GET_ICArms) dori_bear.Set_Arms(ICArms);

	scene.show_BossIntro();

	return true;
}

bool Game::battle(bool do_battle) {

	if (do_battle == false) {
		end.show_BadEnd01();
		return true;
	}
	else {
		scene.show_Boss();
	}


}
