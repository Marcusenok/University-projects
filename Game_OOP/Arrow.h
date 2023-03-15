#pragma once
#include "Projectile.h"
#include "Enemy.h"

class Arrow : public Projectile
{
protected:
	Enemy* target_enemy;

public:
	Arrow();
	Arrow(const Arrow&);
	~Arrow();

	virtual void Update(float dt);
	virtual void SendMsg(MSG* m);
};

