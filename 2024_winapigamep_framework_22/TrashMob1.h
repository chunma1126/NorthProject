#pragma once
#include "Enemy.h"
class TrashMob1 : public Enemy
{
public:
	TrashMob1();
	~TrashMob1();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	int m_hp;
};

