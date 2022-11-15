#include "enum.h"

Item::Item() {
	item = "����";
	item_effect = "   ";
}

bool Item::init_item(int item) { // ������ ���� �� �ʱ�ȭ
	
	if (item == CHEWING_GUM) {
		this->item = "��";
		this->item_effect = "��ȣ���� 10 ����ϴ�.";
	}
	else if (item == COTTON) {
		this->item = "�ع�ġ";
		this->item_effect = "ü���� 10 ȸ���մϴ�.";
	}
	else if (item == INSSA_RABBIT) {
		this->item = "�ν� �䳢";
		this->item_effect = "������ ���ݷ��� �����մϴ�.";
	}
	else if (item == MAGIC_CIRCLE) {
		this->item = "���� ��Ŭ";
		this->item_effect = "�������� 50�� �������� �����ϴ�.";
	}
	else if (item == F_GRADE_CARD) {
		this->item = "F���� ����ǥ";
		this->item_effect = "F���� ����ǥ�� �����ϴ�.";
	}
	else if (item == INF_GAUNTLETS) {
		this->item = "���Ǵ�Ƽ ��Ʋ��";
		this->item_effect = "�� �� �Ѹ��� ������ϴ�.";
	}
	else if (item == MEET_IC) {
		this->item = "���̽�ũ��";
		this->item_effect = "ü���� 20 ȸ���մϴ�.";
	}
	else if (item == NONE) {
		this->item = "����";
		this->item_effect = "    ";
	}
	else if (item == EXIT) {
		this->item = "���� �ݱ�";
		this->item_effect = "    ";
	}
	else {
		this->item = "����";
		this->item_effect = "    ";
	}

	return true;
}

int Item::use_item(Character & player, Character & boss) {

	if (item == "����") {
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("�������� �����ϴ�.");
		Sleep(1500);

		return false;
	}
	if (item == "���� �ݱ�") {
		return EXIT;
	}
	else if (item == "��") { // ����ϸ� ��ȣ�� 10 ����
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("���� ����߽��ϴ�!");
		Sleep(1500);
		control.gotoxy(65, 48);
		printf("��ȣ�� 10�� ������ϴ�!");
		Sleep(1500);
		int shield = player.Get_Shield();
		player.Set_Shield(CHEWING_GUM_SHIELD + shield);
	}
	else if (item == "�ع�ġ") { // ����ϸ� �� 10 ȸ��
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("�ع�ġ�� ����߽��ϴ�!");
		Sleep(1500);
		control.gotoxy(65, 48);
		printf("�� 10�� ȸ���߽��ϴ�!  ");
		Sleep(1500);
		int hp = player.Get_HP();
		if (hp + COTTON_HEAL >= PLAYER_HP) player.Set_HP(PLAYER_HP);
		else player.Set_HP(COTTON_HEAL + hp);
	}
	else if (item == "���̽�ũ��") { // ����ϸ� �� 20 ȸ��
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("���̽�ũ���� ����߽��ϴ�!");
		Sleep(1500);
		control.gotoxy(65, 48);
		printf("�� 20�� ȸ���߽��ϴ�!  ");
		Sleep(1500);
		int hp = player.Get_HP();
		if (hp + ICREAM_HEAL >= PLAYER_HP) player.Set_HP(PLAYER_HP);
		else player.Set_HP(ICREAM_HEAL + hp);
	}
	else if (item == "�ν� �䳢") { // ����ϸ� ���� ���ݷ� 1 ����
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("�ν��䳢���ڸ� ����߽��ϴ�!");
		Sleep(1500);
		control.gotoxy(65, 48);
		printf("������ ���ݷ��� 2 �����߽��ϴ�!");
		Sleep(1500);
		int boss_ad = boss.Get_AttackDamage();
		boss.Set_AttackDamage(boss_ad - INSSA_RABBIT_DM_DOWN);
	}
	else if (item == "���� ��Ŭ") {
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("������Ŭ�� ����߽��ϴ�!");
		Sleep(1500);
		control.gotoxy(65, 48);
		printf("���ֿ��� 50�� �������� �������ϴ�!");
		Sleep(1500);

		int boss_hp = boss.Get_HP(); // ����ϸ� ���� �� 50 ����
		boss.Set_HP(boss_hp - MAGIC_CIRCLE_DM);
	}
	else if (item == "F���� ����ǥ") { // ����ϸ� ���� ���ݷ��� 5���� or c�Ѹ��� �нú갡 ������ ���翣��
		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("F���� ����ǥ�� ����߽��ϴ�!");
		Sleep(1500);

		if (boss.Get_Passive() == F_GRADE_CARD_END)
			return F_GRADE_CARD_END;
		else {
			int boss_ad = boss.Get_AttackDamage();
			boss.Set_AttackDamage(boss_ad + F_GRADE_CARD_DM_UP);
		}
	}
	else if (item == "���Ǵ�Ƽ ��Ʋ��") { // ����ϸ� ���� or �÷��̾� ���߿� �Ѹ� ���, ���� ����
		std::random_device rd;
		std::mt19937 gen(rd());
		std::normal_distribution<> dist(0, 1);

		control.gotoxy(65, 47);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("                                         ");
		control.gotoxy(65, 49);
		printf("                                         ");
		control.gotoxy(65, 50);
		printf("                                         ");
		control.gotoxy(65, 48);
		printf("���Ǵ�Ƽ ��Ʋ���� ����߽��ϴ�!");
		Sleep(1500);

		if (dist(gen) == 0) return INF_GAUNTLETS_END1;
		else return INF_GAUTTLETS_END2;
	}
	else {
		return false;
	}


	init_item(NONE);
	return true;
}

std::string Item::get_item_name() {

	return this->item;
}

std::string Item::get_item_effect() {

	return this->item_effect;

}