#include "Bag.h"
#include "Character.h"
#include "Item.h"


Bag::Bag() {
	bag_item[3].init_item(EXIT); // ������ �׹�° ĭ�� ���� �ݱ�
	bag_size = 0;
}

bool Bag::input_item(int item) { // ���濡 ������ ����
	return this->bag_item[bag_size++].init_item(item);
}

void Bag::bag_list_print() { // �������� ���� ������� �����ִ� �Լ�
	Control::gotoxy(65, 50);
	std::cout << "                                     ";
	Control::gotoxy(65, 51);
	std::cout << "                                     ";
	Control::gotoxy(65, 52);
	std::cout << "                                     ";
	Control::gotoxy(65, 48);
	std::cout << "������ ���� �������� ����Ѵ�!";
	Control::gotoxy(65, 50);
	std::cout << "                                     ";
	Control::gotoxy(65, 51);
	std::cout << "                                     ";
	Control::gotoxy(65, 52);
	std::cout << "                                     ";
	Control::gotoxy(65, 49);
	std::cout << "���� ������";
	Control::gotoxy(65, 50);
	std::cout.width(10);
	std::cout << std::left << bag_item[0].get_item_name();
	Control::gotoxy(75, 50);
	std::cout.width(10);
	std::cout << std::left << bag_item[1].get_item_name();
	Control::gotoxy(85, 50);
	std::cout.width(10);
	std::cout << std::left << bag_item[2].get_item_name();
}

int Bag::bag_open(Character & player, Character & boss) { // �������� ���� ���⸦ ������ ���� �� ���빰�� �����ִ� �Լ�
	Control::gotoxy(65, 47);
	std::cout << "                               ";
	Control::gotoxy(65, 48);
	std::cout << "                               ";
	Control::gotoxy(65, 49);
	std::cout << "                               ";
	Control::gotoxy(65, 50);
	std::cout << "                               ";
	Control::gotoxy(115, 47);
	std::cout << "                               ";
	Control::gotoxy(115, 50);
	std::cout << "                               ";
	int x = 115;
	int y = 47;
	Control::gotoxy(115, 47);
	std::cout << "�� " << bag_item[0].get_item_name();
	Control::gotoxy(65, 47);
	std::cout << bag_item[0].get_item_effect();
	Control::gotoxy(115, 48);
	std::cout << "   " << bag_item[1].get_item_name();
	Control::gotoxy(115, 49);
	std::cout << "   " << bag_item[2].get_item_name();
	Control::gotoxy(115, 50);
	std::cout << "   " << bag_item[3].get_item_name();

	while (1)
	{
		int n = Control::key_control();
		switch (n) {
		case UP:
		{
			if (y > 47)
			{
				Control::gotoxy(x, y);
				std::cout << "   ";
				Control::gotoxy(x, y - 1);
				std::cout << "��";
				y = y - 1;
			}
			break;
		}
		case DOWN:
		{
			if (y < 50)
			{
				Control::gotoxy(x, y);
				std::cout << "   ";
				Control::gotoxy(x, y + 1);
				std::cout << "��";
				y = y + 1;
			}
			break;
		}
		case SUBMIT:
		{
			if (y == 47)
			{
				return bag_item[0].use_item(player, boss);
			}
			else if (y == 48)
			{
				return bag_item[1].use_item(player, boss);
			}
			else if (y == 49)
			{
				return bag_item[2].use_item(player, boss);
			}
			else if (y == 50)
			{
				return bag_item[3].use_item(player, boss);
			}
		}
		}
		if (y == 47)
		{

			Control::gotoxy(x - 50, 48);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 49);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 47);
			std::cout << bag_item[0].get_item_effect();
		}
		else if (y == 48)
		{
			Control::gotoxy(x - 50, 47);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 49);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 48);
			std::cout << bag_item[1].get_item_effect();
		}
		else if (y == 49)
		{
			Control::gotoxy(x - 50, 47);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 48);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 49);
			std::cout << bag_item[2].get_item_effect();
		}
		else if (y == 50)
		{
			Control::gotoxy(x - 50, 47);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 48);
			std::cout << "                                           ";
			Control::gotoxy(x - 50, 49);
			std::cout << "                           ";
			std::cout << bag_item[3].get_item_effect();
		}
	}
	Control::gotoxy(x - 50, 47);
	std::cout << "                                           ";
	Control::gotoxy(x - 50, 48);
	std::cout << "                                           ";
	Control::gotoxy(x - 50, 49);
	std::cout << "                                           ";
	Control::gotoxy(x - 50, 50);
	std::cout << "                                           ";
}