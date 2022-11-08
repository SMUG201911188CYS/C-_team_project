#ifndef __Scene_h__
#define __Scene_h__
#include "Control.h"

class Scene {
protected:
	Control control;
public:
	void text_color_change (int color_number); // �ؽ�Ʈ �� ����
	void show_StartIntro(); // ���� ȭ��
	void show_MainIntro(); // ���� ȭ��
	void show_Scenario(); // �ó����� ȭ��
	void show_Sewer(); // �ϼ��� ȭ��
	void show_crossroads(); // ������ ȭ��
	void show_room(); // �� ȭ��
	void show_BossIntro(); // ������ ���� ȭ��
	void show_Boss(); // ������ ȭ��
};

#endif // !__Scene_h__
