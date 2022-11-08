#ifndef __ITEM_H__

#define __ITEM_H__
#include <vector>
#include <string>
#include "Character.h"
#include <random>

class Item {
private:
	std::string item;
	std::string item_effect;
	enum item_list { // ������ ����Ʈ
		CHEWING_GUM,
		COTTON,
		INSSA_RABBIT = 3,
		INF_GAUNTLETS = 4,
		MAGIC_CIRCLE = 5,
		F_GRADE_CARD = 6,
		NONE = 11
	};
	enum item_effect_list { // ������ ȿ��
		CHEWING_GUM_SHIELD = 10, // �� 10 ȸ��
		COTTON_HEAL = CHEWING_GUM_SHIELD, // �� 10 ȸ��
		INSSA_RABBIT_DM_DOWN = 1, // ���ݷ� 1 ����
		MAGIC_CIRCLE_DM = 50, // 50�� ������ ����
		F_GRADE_CARD_DM_UP = 5, // ���ݷ� 5 ���
		PLAYER_HP = 50, // �÷��̾� �⺻ hp
		BOSS_HP = 200, // ���� �⺻ hp
		F_GRADE_CARD_END = 312, // ����
		INF_GAUNTLETS_END1 = 314, // ����
		INF_GAUTTLETS_END2 = 315 // ����
	};
public:
	Item();
	bool init_item(int item);
	int use_item(Character & character);
	std::string get_item_name();
	std::string get_item_effect();
};


#endif // !__ITEM_H__
