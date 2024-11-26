#pragma once
#include "Enemy.h"
class TrashMob3 : public Enemy
{
public:
	TrashMob3();
	~TrashMob3();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	int m_hp;
public:
	Vec2 ifPlayerPos = { SCREEN_WIDTH / 2.f,600.f };
};

