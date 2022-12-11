#ifndef __SCENE_H__
#define __SCENE_H__
#include "enum.h"

class Scene : public Control {
protected:
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
