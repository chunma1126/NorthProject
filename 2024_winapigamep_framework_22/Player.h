#pragma once
#include "Object.h"
class Texture;
class HealthComponent;
class Player : public Object
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
private:
	const float immortalTimeEnd = 3.f;
	const float defaultSpeed = 200;
	const float runningSpeed = 350;
	const float rpm = 600;
	const Vec2 spawnPosition = Vec2(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 2.5f / 3.f);
	const Vec2 boundary = Vec2(500, 500);
	Vec2 pivotPoint = Vec2(15.f, 15.f);
private:
	bool IsImmortal() { return m_immortalTime < immortalTimeEnd; }
private:
	void Clamp();
	bool TryShoot();
	bool TryUltimite();
	void CreateProjectile();
	void CreateUltmite();
	void Dead();
	void OnHit(Collider* _other);
	void OnTakeDamage();
private:
	float m_immortalTime = 4.f;
	float lastShotTime = 0;
	bool isSlow = false;
	HealthComponent* m_health = nullptr;
	Texture* m_pTex;
	Texture* m_pTexOnHurt;
	Texture* m_pHitbox;
	Texture* m_pFire;
};

