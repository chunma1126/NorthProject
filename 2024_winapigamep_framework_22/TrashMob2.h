#pragma once
#include "Enemy.h"
class TrashMob2 : public Enemy
{
public:
	TrashMob2();
	~TrashMob2();
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
	bool m_right = true;
	void SetRight2Left() {
		m_right = false;
	}
};

