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
		else if (what_Event == box) get_2 = event.box();
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
		else get_3 = NONE;

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
		else get_3 = NONE;

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
		else get_3 = NONE;

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

void Game::hp_print() {

	control.gotoxy(10, 5);
	std::cout << "                           ";
	control.gotoxy(10, 5);
	std::cout << "���� HP : " << princess.Get_HP();
	control.gotoxy(10, 10);
	std::cout << "                           ";
	control.gotoxy(10, 10);
	std::cout << "�÷��̾� HP : " << dori_bear.Get_HP() + dori_bear.Get_Shield();

}

void Game::menu_print() {
	int x = 115;
	int y = 47;
	control.gotoxy(x, y);
	std::cout <<"�� �⺻����";
	control.gotoxy(x - 50, y + 1);
	std::cout <<"���ֿ��� �⺻ ������ ���Ѵ�!";
	control.gotoxy(x, y + 3);
	std::cout <<"   Ư������";
	control.gotoxy(x + 15, y);
	std::cout <<"   ����ϱ�";
	control.gotoxy(x + 15, y + 3);
	std::cout <<"   ���溸��";
}

void Game::boss_turn() {

	int x = 115;
	int y = 47;

	int boss_attack_damage = princess.Skill_Attack(dori_bear, true);

	control.gotoxy(x - 50, y + 3);
	std::cout << "                                     ";
	control.gotoxy(x - 50, y + 1);
	std::cout << "                                     ";
	control.gotoxy(x - 50, y + 2);
	std::cout << "                                     ";
	control.gotoxy(x - 50, y + 1);
	std::cout << "���ְ� " << princess.Get_Last_Attack_Name() << "�� �����ߴ�!";
	Sleep(1500);

	if (boss_attack_damage == 0) {
		control.gotoxy(x - 50, y + 3);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 1);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 2);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 1);
		std::cout << "���ִ��� ���ݷ��� 2 �����Ͽ���!";
		Sleep(1500);
	}
	else {
		control.gotoxy(x - 50, y + 3);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 1);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 2);
		std::cout << "                                     ";
		control.gotoxy(x - 50, y + 1);
		std::cout << "��������� " << boss_attack_damage << "�� ���ظ� �Ծ���!";
		Sleep(1500);
	}
	hp_print();

}


bool Game::battle(bool do_battle) {
	std::string bossListen[8] = { "���� : %&^$#%@!!# %!!!!!!","��������: (����ϱ⸦ ��� �غ���.)","���� : $#^%$&*%^$^#" ,"��������: (����ϱ⸦ ��� �غ���.)","���� : ��>>>�ѤѤҤ�>>>>", "��������: (���� ������ �� ����),","���� : ��>>>>>�����ѤѤ�>>>","��������: (��..���� �� ��ٷ�����)" };
	int listen_cnt = 0;

	test_setting();
	do_battle = true;

	if (do_battle == false) {
		end.show_BadEnd01();
		return true;
	}
	else {
		scene.show_Boss();
	}

	int x = 115;
	int y = 47;
	hp_print();
	control.gotoxy(x, y);
	std::cout << "�� �⺻����";
	control.gotoxy(x - 50, y + 1);
	std::cout << "���ֿ��� �⺻ ������ ���Ѵ�!";
	control.gotoxy(x, y + 3);
	std::cout << "   Ư������";
	control.gotoxy(x + 15, y);
	std::cout << "   ����ϱ�";
	control.gotoxy(x + 15, y + 3);
	std::cout << "   ���溸��";

	while (1) {
		int n = control.key_control();
		switch (n) {
		case UP: {
			if (y > 47)
			{
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, y - 3);
				std::cout << "��";
				y = y - 3;
			}
			break;
		}
		case DOWN: {
			if (y < 50) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, y + 3);
				std::cout << "��";
				y = y + 3;
			}
			break;
		}
		case LEFT: {
			if (x > 115) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x - 15, y);
				std::cout << "��";
				x = x - 15;
			}
			break;
		}
		case RIGHT: {
			if (x < 130) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x + 15, y);
				std::cout << "��";
				x = x + 15;
			}
			break;
		}
		case SUBMIT: {
			if (x == 115 && y == 47) { // �⺻ ����
				control.gotoxy(x - 50, y + 3);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 1);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 2);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 1);
				std::cout << "��������� �Ϲ� ������ �ߴ�!";
				Sleep(1500);

				control.gotoxy(x - 50, y + 3);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 1);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 2);
				std::cout << "                                     ";
				control.gotoxy(x - 50, y + 1);
				std::cout << "���ִԿ��� " << dori_bear.normal_attack(princess) << "�� ���ظ� ������!";
				Sleep(1500);

				hp_print();

				boss_turn();
			}  // �Ϲ� ����

			else if (x == 115 && y == 50) { // Ư������
				if (dori_bear.Get_Arms() == "Wings")
				{
					if (dori_bear.Get_Skill_Count() > 0)
					{
						int end_check = dori_bear.Skill_Attack(princess, true);

						control.gotoxy(x - 50, y - 2);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 2);
						std::cout << "��������� ȸ���������� ����!";
						Sleep(1500);
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                         ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "���ֿ��� 25�� ���ظ� �־���!";
						Sleep(1500);
						control.gotoxy(x - 50, y);
						std::cout << "���ִ� Ǯ�� �׾ �ൿ�� ���� ���ߴ�...";
						Sleep(1500);
						control.gotoxy(10, 5);
						std::cout << "             ";
						control.gotoxy(10, 5);
						hp_print();

						control.gotoxy(x - 50, y);
						std::cout << "                                         ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                         ";

						if (end_check == Wings_end)
						{
							Sleep(1500);
							system("cls");
							end.show_SPEnd04();
							return true;
						}
					}
				}
				else if (dori_bear.Get_Arms() == "CatArms")
				{
					if (dori_bear.Get_Skill_Count() > 0)
					{
						int end_check = dori_bear.Skill_Attack(princess, true);

						control.gotoxy(x - 50, y - 2);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 2);
						std::cout << "��������� �ɳ���ġ�� ����!";
						Sleep(1500);
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                         ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "���ֿ��� 40�� ���ظ� �־���!";
						Sleep(1500);
						control.gotoxy(10, 5);
						std::cout << "             ";
						control.gotoxy(10, 5);

						hp_print();

						if (end_check == Cat_end)
						{
							Sleep(1500);
							system("cls");
							end.show_SPEnd05();
							return true;
						}

						boss_turn();
					}
				}
				else if (dori_bear.Get_Arms() == "ICArms") // ���̽�ũ�� ���
				{
					if (dori_bear.Get_Skill_Count() > 0)
					{
						int end_check = dori_bear.Skill_Attack(princess, true);

						control.gotoxy(x - 50, y - 2);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 2);
						std::cout << "��������� �ڱ� ���� �Ծ���!";
						Sleep(1500);
						control.gotoxy(x - 50, y - 1);
						std::cout << "                                         ";
						control.gotoxy(x - 50, y + 1);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y);
						std::cout << "                                          ";
						control.gotoxy(x - 50, y - 1);
						std::cout << "�Ǹ� 15 ȸ�� �ߴ�!";
						Sleep(1500);

						hp_print();

						boss_turn();

					}
				}
			}

			else if (x == 130 && y == 47) { // ����ϱ�
				control.gotoxy(x - 65, y + 3);
				std::cout << "                                     ";
				control.gotoxy(x - 65, y + 1);
				std::cout << "                                     ";
				control.gotoxy(x - 65, y + 2);
				std::cout << "                                     ";
				control.gotoxy(x - 65, y + 1);
				std::cout << "��������� ����ϱ⸦ ����ߴ�!";
				Sleep(1500);
				if (dori_bear.Get_Passive() == LISTEN)
				{
					if (listen_cnt >= 7)
					{
						system("cls");
						end.show_TrueEnd08();
						return true;
					}
					control.gotoxy(x - 65, y + 3);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 2);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << bossListen[listen_cnt];
					listen_cnt++;
					Sleep(1500);
					control.gotoxy(x - 65, y + 3);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 2);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << bossListen[listen_cnt];
					listen_cnt++;
					Sleep(1500);
					control.gotoxy(x - 65, y + 3);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 2);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
				}
				else
				{
					int boss_attack_damage = princess.Skill_Attack(dori_bear, true);

					control.gotoxy(x - 65, y + 3);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 2);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 1);
					std::cout << "���ְ� " << princess.Get_Last_Attack_Name() << "�� �����ߴ�!";
					Sleep(1500);

					if (boss_attack_damage == 0) {
						control.gotoxy(x - 65, y + 3);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 1);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 2);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 1);
						std::cout << "���ִ��� ���ݷ��� 2 �����Ͽ���!";
						Sleep(1500);
					}
					else {
						control.gotoxy(x - 65, y + 3);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 1);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 2);
						std::cout << "                                     ";
						control.gotoxy(x - 65, y + 1);
						std::cout << "��������� " << boss_attack_damage << "�� ���ظ� �Ծ���!";
						Sleep(1500);
					}
					hp_print();
				}
			}

			else if (x == 130 && y == 50) { // ���� ����
				int check = player_bag.bag_open(dori_bear, princess);

				if (check == F_GRADE_CARD_END) {
					Sleep(1500);
					system("cls");
					end.show_SPEnd07();
					return true;
				}
				else if (check == INF_GAUNTLETS_END1) {
					Sleep(1500);
					system("cls");
					end.show_SPEnd10();
					return true;

				}
				else if (check == INF_GAUTTLETS_END2) {
					Sleep(1500);
					system("cls");
					end.show_SPEnd11();
					return true;
				}
				else if (check == EXIT || check == false) {
					control.gotoxy(115, 47);
					std::cout << "            ";
					control.gotoxy(115, 48);
					std::cout << "            ";
					control.gotoxy(115, 49);
					std::cout << "            ";
					control.gotoxy(115, 50);
					std::cout << "            ";
				}
				else {
					control.gotoxy(x - 65, y + 1);
					std::cout << "                                     ";
					control.gotoxy(x - 65, y + 2);
					std::cout << "                                     ";
					control.gotoxy(115, 47);
					std::cout << "            ";
					control.gotoxy(115, 48);
					std::cout << "            ";
					control.gotoxy(115, 49);
					std::cout << "            ";
					control.gotoxy(115, 50);
					std::cout << "            ";
					hp_print();
					boss_turn();
				}
				control.gotoxy(115, 47);
				std::cout << "   �⺻����";
				control.gotoxy(115, 50);
				std::cout << "   Ư������";
				control.gotoxy(130, 47);
				std::cout << "   ����ϱ�";
				control.gotoxy(130, 50);
				std::cout << "�� ���溸��";
			}
		}
		}

		if (x == 115 && y == 47)
		{
			control.gotoxy(x - 50, y + 3);
			std::cout << "                                     ";
			control.gotoxy(x - 50, y + 1);
			std::cout << "                                     ";
			control.gotoxy(x - 50, y + 2);
			std::cout << "                                     ";
			control.gotoxy(x - 50, y + 1);
			std::cout << "���ֿ��� �⺻ ������ ���Ѵ�!";
		}
		else if (x == 130 && y == 47)
		{
			control.gotoxy(x - 65, y + 3);
			std::cout << "                                     ";
			control.gotoxy(x - 65, y + 1);
			std::cout << "                                     ";
			control.gotoxy(x - 65, y + 2);
			std::cout << "                                     ";
			control.gotoxy(x - 65, y + 1);
			std::cout << "���ְ� �ִ� ���ظ� ����Ѵ�!";
		}
		else if (x == 115 && y == 50)
		{
			control.gotoxy(x - 50, y - 1);
			std::cout << "                                        ";
			control.gotoxy(x - 50, y);
			std::cout << "                                        ";
			control.gotoxy(x - 50, y + 1);
			std::cout << "                                        ";
			control.gotoxy(x - 50, y + 2);
			std::cout << "                                        ";
			control.gotoxy(x - 50, y - 2);
			std::cout << "���ֿ��� Ư�� ���ظ� ���Ѵ�!      ";

			if (dori_bear.Get_Skill_Count() >= 1)
			{
				control.gotoxy(x - 50, y);
				std::cout << dori_bear.Get_Skill_Discription();
				std::cout << "(" << dori_bear.Get_Skill_Count() << "��)";
			}
			else
			{
				control.gotoxy(x - 50, y);
				std::cout << "��� �� �� �����.";
			}

		}
		else if (x == 130 && y == 50)
		{
			player_bag.bag_list_print();
		}

		if (princess.Get_HP() == 0)
		{
			Sleep(1500);
			system("cls");
			if (dori_bear.Get_Arms() == "Dori_Bear_arms")
			{
				end.show_SPEnd06();
				return true;
			}
			end.show_NorEnd09();
			return true;
		}
		if (dori_bear.Get_HP() == 0)
		{
			Sleep(3000);
			system("cls");
			if (dori_bear.Get_Passive() == DEADHARD)
			{
				end.show_SPEnd03();
				return true;
			}
			end.show_BadEnd02();
			return true;
		}
	}
}


void Game::test_setting() {
	
	using std::cout;
	using std::cin;
	using std::endl;

	while (1) {
		cout << "���� ������" << endl;
		cout << "1. �������� �� // 2. ���� // 3. �������� // 4. ����� �� // 5. ���� �� // 6. ���̽�ũ�� ��" << endl;
		cout << ">>";
		int arm_temp = 0;
		cin >> arm_temp;

		if (arm_temp > 6 || arm_temp < 1) {
			cout << "�ٽ� �Է�" << endl;;
		}
		else {
			this->dori_bear.Set_Arms(arm_temp + 14);
			break;
		}
	}

	while (1) {
		cout << "�нú긦 ������" << endl;
		cout << "1. �����ϵ� // 2. ���Ѹ��� // 3. ��û�ϱ�" << endl;
		cout << ">>";
		int passive_temp = 0;
		cin >> passive_temp;

		if (passive_temp == 1) {
			this->dori_bear.Set_Passive(DEADHARD);
			break;
		}
		else if (passive_temp == 2) {
			this->dori_bear.Set_Passive(FARMING);
			break;
		}
		else if (passive_temp == 3) {
			this->dori_bear.Set_Passive(LISTEN);
			break;
		}
		else {
			cout << "�ٽ� �Է�" << endl;
		}
	}

	int i = 0;
	int item_temp = 0;
	while (i < 3) {
		cout << "�������� ������ (�ִ� 3�� // " << i << "���� �� Ƚ��)" <<endl;
		cout << "1. �� (��ȣ�� 10 ȹ��)" << endl;
		cout << "2. �� (ü�� 10 ȸ��)" << endl;
		cout << "3. ���� (����)" << endl;
		cout << "4. �ν��䳢 (���� ���ݷ� 2 ����)" << endl;
		cout << "5. ���Ǵ�Ƽ ��Ʋ�� (1/2Ȯ���� ��� kill or �� kill)" << endl;
		cout << "6. ������Ŭ (�������� 50�� ������)" << endl;
		cout << "7. f���� ����ǥ (���Ѹ��� �ִ� ���·� ���� ���翣��)" << endl;
		cout << ">>";
		cin >> item_temp;

		if (item_temp > 7 || item_temp < 1) {
			cout << "�ٽ� �Է�" << endl;
		}
		else {
			this->player_bag.input_item(item_temp);
			i++;
		}

	}
}