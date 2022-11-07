#include "Item.h"

Item::Item() {
	item = "����";
	item_effect = "   ";
}

bool Item::init_item(int item) {
	
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
	else {
		this->item = "����.";
		this->item_effect = "    ";
	}

	return true;
}

int Item::use_item() {

	if (item == "����") return 101;
	else if (item == "��") return 10;
	else if (item == "�ν� �䳢") return 1;
	else if (item == "���� ��Ŭ") return 50;
	else if (item == "F���� ����ǥ") return 102;
	else if (item == "���Ǵ�Ƽ ��Ʋ��") return 103;

}