#include <iostream>
#include "Event.h"
#include <Windows.h>

Event::Event() {
	rand_value = 0;
}

int Event::rand() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> dist(0, 9);

	return dist(gen);
}

int Event::pot() {
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�׾Ƹ� ������.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�׾Ƹ� ������..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�׾Ƹ� ������...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�׾Ƹ� ������.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�׾Ƹ� ������..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	rand_value = 2;
	
	if (pot_item_percent[rand_value] == COTTON)
	{
		std::cout << "�ع�ġ�� ������ϴ�.";
		return COTTON;
		Sleep(1000);

	}
	else if (pot_item_percent[rand_value] == CHEWING_GUM)
	{
		std::cout << "���� ������ϴ�.";
		Sleep(1000);
		return CHEWING_GUM;

	}
	else
	{
		std::cout << "�ƹ��͵� ������ �ʾҽ��ϴ�...";
		return NONE;
	}

}

int Event::box() {
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� ������.";
	Sleep(1000);
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� ������..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� ������...";
	Sleep(1000);
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� ������.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� ������..";
	Sleep(1000);
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	rand_value = rand();

	if (box_item_percent[rand_value] == COTTON)
	{
		std::cout << "�ع�ġ�� ������ϴ�.";
		Sleep(1000);
		return COTTON;
	}
	else if (box_item_percent[rand_value] == CHEWING_GUM)
	{
		std::cout << "���� ������ϴ�.";
		Sleep(1000);
		return CHEWING_GUM;

	}
	else if (box_item_percent[rand_value] == NONE)
	{
		std::cout << "�ƹ� �͵� ������ �ʾҽ��ϴ�...";
		return NONE;
	}
	else if (box_item_percent[rand_value] == INSSA_RABBIT)
	{
		std::cout << "�ν��䳢�� ������ϴ�.";
		Sleep(1000);
		return INSSA_RABBIT;

	}
	else if (box_item_percent[rand_value] == INF_GAUNTLETS)
	{
		std::cout << "WoW !!!! ���Ǵ�Ƽ ��Ʋ���� ������ϴ�.";
		Sleep(1000);
		return INF_GAUNTLETS;

	}
}

int Event::hole()
{
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ �ĺ�����.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ �ĺ�����..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ �ĺ�����...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ �ĺ�����.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ �ĺ�����..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���� �̽� �غ�.....��";
	return NONE;
}

int Event::bookshelf()
{
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "å�� ������ ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "å�� ������ ��..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "å�� ������ ��...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "å�� ������ ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "å�� ������ ��..";
	Sleep(1000);
	rand_value = rand();

	if (book_item_percent[rand_value] == MATH) // ������ ����
	{
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "������ �����̶�� å�̴�.";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "���⸸ �ص� ��� ���ڴ� �׳� ����.";
	}
	else if (book_item_percent[rand_value] == TAGD) // TAGD
	{
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "The Art Of Game Design �̶�� å�̴�..";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "��� ��ħ���� ���� �� ����.";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "�� �ϼ����� ������ �� �ʿ�� ���� �� ����.";
	}
	else if (book_item_percent[rand_value] == GET_FARMING) // ����� ����, C�Ѹ��� ȹ��
	{
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "����� �����̶�� å�̴�.";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "'��������'C�Ѹ��⿡ ���� ������ �����ִ�.";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "å�� �а� C�Ѹ��⸦ �����!";
		Sleep(3000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "F���� ����ǥ�� ���ֿ��� ����ϸ� Ư���� ���� �Ͼ����...?";
	}

	return NONE;
}

int Event::mouse() {

	rand_value = rand();
	char a[] = "������ �㰡 ������ �������� ġ� ������ ���� �˱⿡,,";
	char b[] = "������ ��������.";

	if (mouse_item_percent[rand_value] == NONE)
	{
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "���� �㱸���ΰ� ����.";
		return NONE;
	}

	else if (mouse_item_percent[rand_value] == GET_CHEESE)
	{
		system("cls");
		for (int i = 0; i < strlen(a); i++)
		{
			control.gotoxy((i * 2) + 20, 25);
			std::cout << a[i];
			Sleep(200);
		}
		for (int i = 0; i < strlen(b); i++)
		{
			control.gotoxy((i * 2) + 57, 27);
			std::cout << b[i];
			Sleep(200);
		}
		return GET_CHEESE;
	}


}

int Event::circle() {

	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�̻��� �� Ž����.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�̻��� �� Ž����..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�̻��� �� Ž����...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�̻��� �� Ž����.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�̻��� �� Ž����..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	rand_value = rand();

	if (circle_item_percent[rand_value] == NONE)
	{
		std::cout << "�ƹ��ϵ�.. ������..";
	}
	else if (circle_item_percent[rand_value] == MAGIC_CIRCLE)
	{
		std::cout << "�ƴ� �̰���....?";
		Sleep(1000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "Magic Circle�� ȹ���Ͽ����ϴ�!!";
		Sleep(1000);
		return MAGIC_CIRCLE;
	}
}

int Event::button() {
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "����ġ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "����ġ�� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "����ġ�� ����.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "����ġ�� ������.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "����ġ�� ��������..";
	Sleep(1000);
	rand_value = rand();


	if (button_tiem_percent[rand_value] == NONE)
	{
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "�������� �ƹ� �ϵ� ������.";
	}
	else if (button_tiem_percent[rand_value] = GET_DEADHARD)
	{
		system("cls");
		control.gotoxy(2, 2);
		std::cout << "(���...)";
		Sleep(1000);
		system("cls");
		control.gotoxy(20, 10);
		std::cout << "(���......)";
		Sleep(1000);
		system("cls");
		control.gotoxy(40, 20);
		std::cout << "(�Ɽ.........)";
		Sleep(2000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "��� ���Ҹ��� �鸮�µ�...?";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "(��������ȤǾƤǰ����վ�)";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "�������Ĥ����Ĥ�!!!! �� �� �� !!!!!!!!!!!!!";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "��������� �ױ���� ��θ� Ż���ߴ�!";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "��������� �ױ��⸦ �����!!!";
		Sleep(3000);
		system("cls");

		return GET_DEADHARD;
	}
}

int Event::paper() {
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�������� ���纸�� ��.";
	Sleep(1000);
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�������� ���纸�� ��..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�������� ���纸�� ��...";
	Sleep(1000);
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�������� ���纸�� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "�������� ���纸�� ��..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	rand_value = rand();

	if (paper_item_percent[rand_value] == NONE)
	{
		std::cout << "���纸��.. û�������ٰ��Ѵ�..";
		return NONE;
	}
	else if (paper_item_percent[rand_value] == F_GRADE_CARD)
	{
		std::cout << "���....? F���� ����ǥ�ΰ�...?";
		Sleep(1000);
		system("cls");
		control.gotoxy(65, 25);
		std::cout << "F ���� ����ǥ�� ������ϴ�.";
		Sleep(1000);
		return F_GRADE_CARD;
	}
}

int Event::npc(int sewer_in)
{
	system("cls");
	rand_value = rand();
	
	if (npc_item_percent[rand_value] == MEET_IC) // ���̽�ũ�� ����
	{
		control.gotoxy(55, 25);
		std::cout << "���̽�ũ�� �缼��!!! �� �� 20���!!!";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "���� ���ٰ��??? �׷� �׳� �帱�Կ�!!!";
		Sleep(3000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "���̽�ũ���� ������ϴ�!!! ��ȣ!!!";
		Sleep(1000);
		return MEET_IC;
	}
	else if (npc_item_percent[rand_value] == MEET_HOMELESS) // �����
	{
		if (sewer_in == 1) {
			system("cls");
			control.gotoxy(55, 25);
			std::cout << "??? : ����....";
			Sleep(3000);
			system("cls");
			control.gotoxy(55, 25);
			std::cout << "�̻��� ����� �� ����.";
			Sleep(3000);
			control.gotoxy(55, 30);
			std::cout << "�� ���� �Ǵ�";
			control.gotoxy(55, 31);
			std::cout << "   ��� ���ڴ� �׳� ����";
			int x = 55;
			int y = 30;
			while (1) {
				int n = control.key_control();
				switch (n) {
				case UP: {
					if (y > 30) {
						control.gotoxy(x, y);
						std::cout << "   ";
						control.gotoxy(x, --y);
						std::cout << "��";
					}
					break;
				}
				case DOWN: {
					if (y < 31) {
						control.gotoxy(x, y);
						std::cout << "   ";
						control.gotoxy(x, ++y);
						std::cout << "��";
					}
					break;
				}
				case SUBMIT: {
					if (y == 30) {
						system("cls");
						control.gotoxy(55, 25);
						std::cout << "??? : ��,,���,,,��";
						Sleep(3000);
						control.gotoxy(55, 30);
						std::cout << "�� ���� ��� �ɾ��";
						control.gotoxy(55, 31);
						std::cout << "   ��� ���ڸ� ��� ����. �׳� ����";
						x = 55, y = 30;
						while (1) {
							switch (n) {
							case UP: {
								if (y > 30) {
									control.gotoxy(x, y);
									std::cout << "   ";
									control.gotoxy(x, --y);
									std::cout << "��";
								}
								break;
							}
							case DOWN: {
								if (y < 31) {
									control.gotoxy(x, y);
									std::cout << "   ";
									control.gotoxy(x, ++y);
									std::cout << "��";
								}
								break;
							}
							case SUBMIT: {
								if (y == 30) {
									system("cls");
									control.gotoxy(55, 25);
									std::cout << "??? : ���ְ�,, ȭ�� ���־�,,";
									Sleep(3000);
									control.gotoxy(55, 30);
									std::cout << "�� ���� ������ �ڼ��� �����";
									x = 55, y = 30;
									while (1) {
										int n = control.key_control();
										switch (n) {
										case SUBMIT: {
											if (y == 30) {
												system("cls");
												control.gotoxy(55, 25);
												std::cout << "??? : ���ִ��� ���� ������ ȭ�� �ܶ� ���־�..";
												Sleep(3000);
												control.gotoxy(55, 27);
												std::cout << "      ȭ�� ��ü���� ���ϰ� ���Ͻǿ��� ����� ���ϰ� ����...";
												Sleep(3000);
												control.gotoxy(55, 29);
												std::cout << "�������� : ��� �ϸ� ������Ű��?";
												Sleep(3000);
												system("cls");
												control.gotoxy(55, 25);
												std::cout << "??? : ���� ��δ��� �׻� ���ϼ���...";
												Sleep(3000);
												control.gotoxy(55, 27);
												std::cout << "      �Ȼ����� ���� �߿��� ���� '��û�ϱ�'���...";
												Sleep(3000);
												control.gotoxy(55, 29);
												std::cout << "      �׳ฦ �������� ���� �͸� ��￩��....";
												Sleep(3000);
												control.gotoxy(55, 31);
												std::cout << "	  '����ϱ�'�� �ϴ� ���� ������������.....";
												Sleep(3000);
												system("cls");
												control.gotoxy(55, 25);
												std::cout << "��û�ϱ⸦ �����.";
												Sleep(3000);
												return GET_LISTEN;
											}
										}
										}
									}
								}
								else { return NONE; }
							}
							}

						}
					}
					else { return NONE; }
				}
				}
			}
		}
		else {
			control.gotoxy(65, 25);
			std::cout << "�ڰ� �ִ� ����ڴ�.";
			return NONE;
		}
	}
}


int Event::pipe(int sewer_in) // ������Ʈ ��� : ������
{
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ ���� �������� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ ���� �������� ��..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ ���� �������� ��...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ ���� �������� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "������ ���� �������� ��..";
	Sleep(1000);
	system("cls");

	if (sewer_in == 1) // c���� �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "������ �ȿ��� �޹��� ������ �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "�޹��� ������ ���������� �ȿ� �����Ͽ���!!";
		Sleep(1000);
		return GET_Wings;
	}

	else if (sewer_in == 2) // G417 �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "������ �ȿ��� ����� ���� �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "����� ���� �� �ȿ� �����Ͽ���!!";
		Sleep(1000);
		return GET_CatArms;
	}

	else if (sewer_in == 3) // ����� �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "������ �ȿ��� ���������� ���� �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "(����?!?! �̰��� �� �����ݾ�?!?!)";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "���������� ���� �����Ͽ���!";
		Sleep(1000);
		return GET_DoriArms;
	}

}

int Event::lake(int sewer_in) // ������Ʈ ��� : ���� ��
{
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���ι� ���� �������� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���ι� ���� �������� ��..";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���ι� ���� �������� ��...";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���ι� ���� �������� ��.";
	Sleep(1000);
	system("cls");
	control.gotoxy(65, 25);
	std::cout << "���ι� ���� �������� ��..";
	Sleep(1000);
	system("cls");

	if (sewer_in == 1) // c���� �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "���� �� �ȿ��� ���������� �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "���������� ���������� �ȿ� �����Ͽ���!!";
		Sleep(1000);
		return GET_Twigs;
	}

	else if (sewer_in == 2) // G417 �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "���� �� �ȿ��� �ٺ������� ���� �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "�ٺ������� ���� �� �ȿ� �����Ͽ���!!";
		Sleep(1000);
		return GET_BarbieArms;
	}

	else if (sewer_in == 3) // ����� �ϼ���
	{
		control.gotoxy(55, 25);
		std::cout << "���� �� �ȿ��� ���̽�ũ�� ���� �߰��ߴ�!!";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "(����..? ���� �� �ȿ� ���̽�ũ����..?)";
		Sleep(1000);
		system("cls");
		control.gotoxy(55, 25);
		std::cout << "���̽�ũ�� ���� �����Ͽ���!";
		Sleep(1000);
		return GET_BarbieArms;
	}
}