#include "enum.h"

Room::Room() {
	this->sewer_in = 0;
	this->cross_in[0] = 0;
	this->cross_in[1] = 0;
	this->cross_in[2] = 0;
	this->x = 36;
	this->y = 24;
}

bool Room::intro() {
	control.gotoxy(36, START);
	std::cout << "��";
	control.gotoxy(36, y + EXIT);
	std::cout << "   ";

	while (1)
	{
		int n = control.key_control();
		switch (n)
		{
		case UP:
		{
			if (y > START)
			{
				control.gotoxy(36, EXIT);
				std::cout << "   ";
				y += -7;
				control.gotoxy(36, START);
				std::cout << "��";
			}
			break;
		}
		case DOWN:
		{
			if (y < EXIT)
			{
				control.gotoxy(36, START);
				std::cout << "   ";
				y += 7;
				control.gotoxy(36, EXIT);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT:
		{
			if (y == START) return true;
			else return false;
		}
		}
	}
}

bool Room::sewer() {
	x = 0;
	y = 50;
	control.gotoxy(x, L);
	std::cout << "�� ���� �ϼ���";
	control.gotoxy(x, M);
	std::cout << "   ��� �ϼ���";
	control.gotoxy(x, R);
	std::cout << "   ������ �ϼ���";
	while (sewer_in == 0) {
		int n = control.key_control();
		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == 50) { // � �ϼ����� �����ߴ��� ����� ����
				this->sewer_in = 1;
			}
			else if (y == 51) {
				this->sewer_in = 2;
			}
			else if (y == 52) {
				this->sewer_in = 3;
			}
			return true;
		}
		}
	}
	return true;
}

bool Room::crossroad() {

	x = 0, y = 50;
	control.gotoxy(x, y);
	std::cout << "�� ���� ��";
	control.gotoxy(x, y + 1);
	std::cout << "   ��� ��";
	control.gotoxy(x, y + 2);
	std::cout << "   ������ ��";
	while (1) {
		int n = control.key_control();
		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) { // ���⼭ ���� �־��ְ� �� ���� main�Լ��� �����ְ� �� ���� ���� main�Լ����� ������ �̵����Ѿ� ��.
				if (cross_in[0] == 0) {
					cross_in[0] = 1;
				}
				else if (cross_in[1] == 0) {
					cross_in[1] = 1;
				}
				else if (cross_in[2] == 0) {
					cross_in[2] = 1;
				}
				return true;
			}
			else if (y == M) {
				if (cross_in[0] == 0) {
					cross_in[0] = 2;
				}
				else if (cross_in[1] == 0) {
					cross_in[1] = 2;
				}
				else if (cross_in[2] == 0) {
					cross_in[2] = 2;
				}
				return true;
			}
			else if (y == R) {
				if (cross_in[0] == 0) {
					cross_in[0] = 3;
				}
				else if (cross_in[1] == 0) {
					cross_in[1] = 3;
				}
				else if (cross_in[2] == 0) {
					cross_in[2] = 3;
				}
				return true;
			}
		}
		}
	}

}

int Room::c_room1_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �׾Ƹ�";
	control.gotoxy(0, M);
	std::cout << "   ����";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return pot;
			}
			else if (y == M) {
				return box;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::c_room1_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ��������";
	control.gotoxy(0, M);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return paper;
			}
			else if (y == M) {
				return pot;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}


int Room::c_room1_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ��������";
	control.gotoxy(0, M);
	std::cout << "   ����";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return paper;
			}
			else if (y == M) {
				return box;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::c_room2_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� å��";
	control.gotoxy(0, M);
	std::cout << "   �̻��� ���";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "å�忡���� ����� ����, ������ ����, The art of game design�� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return bookshelf;
			}
			else if (y == M) {
				return npc;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "å�忡���� ����� ����, ������ ����, The art of game design�� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::c_room2_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ����";
	control.gotoxy(0, M);
	std::cout << "   å��";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return box;
			}
			else if (y == M) {
				return bookshelf;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "å�忡���� ����� ����, ������ ����, The art of game design�� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::c_room2_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(x + 15, L);
	std::cout << "�����̴� �����ϱ��?";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case SUBMIT: {
			if (y == L) {
				return hole;
			}
		}
		}
	}
}

int Room::c_room3_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return pipe;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::c_room3_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ���ι�";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return lake;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::c_room3_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ��������";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return paper;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

// normal room

int Room::n_room1_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ��������";
	control.gotoxy(0, M);
	std::cout << "   ����";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return paper;
			}
			else if (y == M) {
				return box;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::n_room1_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �㱸��";
	control.gotoxy(0, M);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "ġ� ���Դϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return mouse;
			}
			else if (y == M) {
				return pot;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}


int Room::n_room1_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ����";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return box;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::n_room2_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ����ġ";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   �̻��� ���";
	control.gotoxy(x + 15, L);
	std::cout << "����ġ�� ������ � ���� �߻��� ���� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return button;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return npc;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "����ġ�� ������ � ���� �߻��� ���� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::n_room2_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ����";
	control.gotoxy(0, M);
	std::cout << "   ����ġ";
	control.gotoxy(0, R);
	std::cout << "   ��������";
	control.gotoxy(x + 15, L);
	std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return box;
			}
			else if (y == M) {
				return button;
			}
			else if (y == R) {
				return paper;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "����ġ�� ������ � ���� �߻��� ���� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::n_room2_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(x + 15, L);
	std::cout << "�����̴� �����ϱ��?";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case SUBMIT: {
			if (y == L) {
				return hole;
			}
		}
		}
	}
}

int Room::n_room3_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   ����";
	control.gotoxy(x + 15, L);
	std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return pipe;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return box;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::n_room3_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ���ι�";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return lake;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::n_room3_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �㱸��";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "ġ� ���Դϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return mouse;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

// g417 room


int Room::g_room1_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ����";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   ��������";
	control.gotoxy(x + 15, L);
	std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return box;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return paper;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::g_room1_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �㱸��";
	control.gotoxy(0, M);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "ġ� ���Դϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return mouse;
			}
			else if (y == M) {
				return pot;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, M);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}


int Room::g_room1_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(x + 15, L);
	std::cout << "�����̴� �����ϱ��?";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case SUBMIT: {
			if (y == L) {
				return hole;
			}
		}
		}
	}
}

int Room::g_room2_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �̻��� ��";
	control.gotoxy(0, M);
	std::cout << "   ����";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "�̻��� ������ Magic Circle�� ȹ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return circle;
			}
			else if (y == M) {
				return box;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "�̻��� ������ Magic Circle�� ȹ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::g_room2_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �̻��� ���";
	control.gotoxy(0, M);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(0, R);
	std::cout << "   ����";
	control.gotoxy(x + 15, L);
	std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return npc;
			}
			else if (y == M) {
				return pot;
			}
			else if (y == R) {
				return box;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::g_room2_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� �̻��� ���";
	control.gotoxy(0, M);
	std::cout << "   �̻��� ��";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return npc;
			}
			else if (y == M) {
				return circle;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "��ü�� �� �� �����ϴ�. Ư�� �̺�Ʈ�� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�̻��� ������ Magic Circle�� ȹ���� �� �ֽ��ϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::g_room3_1() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ������";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   ������";
	control.gotoxy(x + 15, L);
	std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return pipe;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return hole;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "������������ ���������� ���� ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�����̴� �����ϱ��?";
		}
	}
}

int Room::g_room3_2() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ���ι�";
	control.gotoxy(0, M);
	std::cout << "   �㱸��";
	control.gotoxy(0, R);
	std::cout << "   ����";
	control.gotoxy(x + 15, L);
	std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return lake;
			}
			else if (y == M) {
				return mouse;
			}
			else if (y == R) {
				return box;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "���ι� ���� ������ ���� ���� �� �����ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "ġ� ���Դϴ�.";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "���ڿ����� ��, �ع�ġ, �ν��䳢, ���Ǵ�Ƽ ��Ʋ��, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::g_room3_3() {
	x = 0, y = 50;

	control.gotoxy(0, L);
	std::cout << "�� ��������";
	control.gotoxy(0, M);
	std::cout << "   ������";
	control.gotoxy(0, R);
	std::cout << "   �׾Ƹ�";
	control.gotoxy(x + 15, L);
	std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";

	while (1) {
		int n = control.key_control();

		switch (n) {
		case UP: {
			if (y > L) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, --y);
				std::cout << "��";
			}
			break;
		}
		case DOWN: {
			if (y < R) {
				control.gotoxy(x, y);
				std::cout << "   ";
				control.gotoxy(x, ++y);
				std::cout << "��";
			}
			break;
		}
		case SUBMIT: {
			if (y == L) {
				return paper;
			}
			else if (y == M) {
				return hole;
			}
			else if (y == R) {
				return pot;
			}
		}
		}
		if (y == L)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "�������������� F���� ����ǥ,û������ ���� �� �ֽ��ϴ�.";
		}
		else if (y == M)
		{
			control.gotoxy(x + 15, R);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, L);
			std::cout << "                                                                                 ";
			control.gotoxy(x + 15, M);
			std::cout << "�����̴� �����ϱ��?";
		}
		else if (y == R)
		{
			control.gotoxy(x + 15, M);
			std::cout << "                                                                              ";
			control.gotoxy(x + 15, R);
			std::cout << "�׾Ƹ������� ��, �ع�ġ, ���� ���� �� �ֽ��ϴ�.";
		}
	}
}

int Room::Get_Crossroad_In(int index) {
	return cross_in[index];
}

int Room::Get_Sewer_in() {
	return sewer_in;
}