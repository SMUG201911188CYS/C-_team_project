#ifndef __CONTROL_H__
#define __CONTROL_H__

class Control {
private:
	int x;
	int y;
public:
	Control();
	void delete_blink(); // Ű���� �����̴°� ���ֱ�
	void gotoxy(int x, int y); // �̵��ϱ�
	int key_control(); // �Է��ϴ� Ű �����ϱ�
};


#endif // !__Control_h__
