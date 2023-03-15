#pragma once
#include"GameObject.h"

enum class MsgType{Move, Death, Create, DealDmg};

struct MSG
{
	MsgType type;
	GameObject* sender;
	union 
	{
		struct{
			Vector2 old_position;
		} move;
		struct{
			GameObject* who_to_die;
			GameObject* killer;
		} death;
		struct{
			GameObject* new_object;
		} create;
		struct{
			float damae;
			GameObject* to_who;
			GameObject* by_whom;
		} deal_dmg;
	};
};

