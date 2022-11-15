#ifndef __EMUM_H__

#define __EMUM_H__

#include <iostream>
#include <string>
#include <random>
#include <conio.h>
#include <vector>
#include <Windows.h>

#include "Control.h"
#include "Scene.h"
#include "Ending.h"
#include "Room.h"
#include "Event.h"
#include "Character.h"
#include "Item.h"
#include "Bag.h"

enum keboard { // Ű �Է� enum
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SUBMIT,
	START = 24,
	EXIT = 31,
	L = 50,
	M = 51,
	R = 52
};

enum item_effect_list { // ������ ȿ��
	CHEWING_GUM_SHIELD = 10, // �� 10 ȸ��
	CHEESE_SHIELD = CHEWING_GUM_SHIELD,
	ICREAM_HEAL = 20, // �� 20 ȸ��
	COTTON_HEAL = CHEWING_GUM_SHIELD, // �� 10 ȸ��
	INSSA_RABBIT_DM_DOWN = 2, // ���ݷ� 2 ����
	MAGIC_CIRCLE_DM = 50, // 50�� ������ ����
	F_GRADE_CARD_DM_UP = 5, // ���ݷ� 5 ���
	PLAYER_HP = 50, // �÷��̾� �⺻ hp
	BOSS_HP = 200, // ���� �⺻ hp
	F_GRADE_CARD_END = 312, // ����
	INF_GAUNTLETS_END1 = 314, // ����
	INF_GAUTTLETS_END2 = 315 // ����
};

enum passive {
	DEADHARD = 7,
	FARMING = 11,
	LISTEN = 14
};
enum item_list { // ������ �̸�
	CHEWING_GUM,
	COTTON,
	NONE,
	INSSA_RABBIT,
	INF_GAUNTLETS,
	MAGIC_CIRCLE,
	F_GRADE_CARD,
	GET_DEADHARD,
	GET_CHEESE,
	MATH,
	TAGD,
	GET_FARMING,
	MEET_IC,
	MEET_HOMELESS,
	GET_LISTEN,
	GET_DoriArms,
	GET_Wings,
	GET_Twigs,
	GET_CatArms,
	GET_BarbieArms,
	GET_ICArms,
};

enum Arms {
	Dori_Bear_arms = 15,
	Wings = 16,
	Twigs = 17,
	CatArms = 18,
	BarbieArms = 19,
	ICArms = 20,
	Wings_end = 412,
	Cat_end = 414,
};

enum object { // �� ���� ������Ʈ ��ϵ� enum
	pot,
	box,
	hole,
	bookshelf,
	circle,
	paper,
	button,
	mouse,
	npc,
	pipe,
	lake
};

enum num {
	FIRST,
	SECOND,
	THIRD
};

#endif // !__EMUM_H__

