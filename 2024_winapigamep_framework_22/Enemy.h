#pragma once
#include "Object.h"
class HealthComponent;
class Enemy :
    public Object
{
public:
	Enemy();
	~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	HealthComponent* m_health = nullptr;
};

