#include "Item.h"

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
	else if (item == NONE) {
		this->item = "����";
		this->item_effect = "    ";
	}
	else {
		this->item = "����";
		this->item_effect = "    ";
	}

	return true;
}

int Item::use_item(Character & character) {

	if (item == "����") {
		return false;
	}
	else if (item == "��") { // ����ϸ� ��ȣ�� 10 ����
		int shield = character.Get_Shield();
		character.Set_Shield(CHEWING_GUM_SHIELD + shield);
	}
	else if (item == "�ع�ġ") { // ����ϸ� �� 10 ȸ��
		int hp = character.Get_HP();
		if (hp + COTTON_HEAL > PLAYER_HP) character.Set_HP(PLAYER_HP);
		else character.Set_HP(COTTON_HEAL + hp);
	}
	else if (item == "�ν� �䳢") { // ����ϸ� ���� ���ݷ� 1 ����
		int boss_ad = character.Get_AttackDamage();
		character.Set_AttackDamage(boss_ad - INSSA_RABBIT_DM_DOWN);
	}
	else if (item == "���� ��Ŭ") {
		int boss_hp = character.Get_HP(); // ����ϸ� ���� �� 50 ����
		character.Set_HP(boss_hp - MAGIC_CIRCLE_DM);
	}
	else if (item == "F���� ����ǥ") { // ����ϸ� ���� ���ݷ��� 5���� or c�Ѹ��� �нú갡 ������ ���翣��
		if (character.Get_Passive() == F_GRADE_CARD_END)
			return F_GRADE_CARD_END;
		else {
			int boss_ad = character.Get_AttackDamage();
			character.Set_AttackDamage(boss_ad + F_GRADE_CARD_DM_UP);
		}
	}
	else if (item == "���Ǵ�Ƽ ��Ʋ��") { // ����ϸ� ���� or �÷��̾� ���߿� �Ѹ� ���, ���� ����
		std::random_device rd;
		std::mt19937 gen(rd());
		std::normal_distribution<> dist(0, 1);

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