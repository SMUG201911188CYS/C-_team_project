#ifndef __Control_h__
#define __Control_h__

class Control {
private:
	int x;
	int y;
public:
	enum {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SUBMIT
	};
	Control();
	void delete_blink(); // Ű���� �����̴°� ���ֱ�
	void gotoxy(int x, int y); // �̵��ϱ�
	int key_control(); // �Է��ϴ� Ű �����ϱ�
};


#endif // !__Control_h__
