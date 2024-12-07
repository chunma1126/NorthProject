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
	const Vec2 boundaryMin = Vec2(0, 0);
	const Vec2 boundaryMax = Vec2(SCREEN_WIDTH, SCREEN_HEIGHT);
	Vec2 pivotPoint = Vec2(13.f, 15.f);
private:
	bool IsImmortal() { return m_immortalTime < immortalTimeEnd; }
private:
	bool TryShoot();
	bool TryUltimite();
	void CreateProjectile();
	void CreateUltmite();
	void Dead();
	void OnHit(Collider* _other);
	void OnTakeDamage();
	void OnLevelUp();
private:
	bool m_isDead = false;
	bool isSlow = false;

	float m_immortalTime = 4.f;
	float lastShotTime = 0;

	int m_level = 1;

	HealthComponent* m_health = nullptr;
	Texture* m_pTex;
	Texture* m_pTexOnHurt;
	Texture* m_pHitbox;
	Texture* m_pFire;

	Texture* m_explosion;
};

