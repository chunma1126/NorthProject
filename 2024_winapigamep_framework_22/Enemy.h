#pragma once
#include "Object.h"
class Texture;
class HealthComponent;
class Enemy :
    public Object
{
public:
	Enemy();
	Enemy(const wstring& _key, const wstring& _path);
	~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	Texture* m_texture = nullptr;
	HealthComponent* m_health = nullptr;
};

