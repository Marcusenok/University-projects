#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:	
	int damage_to_player;
	int loot;
	float maxhp, hp;
	Vector2 direction;
	float velocity;

public:
	Enemy();
	virtual ~Enemy();

	virtual void Move(float dt);
};

