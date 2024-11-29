#pragma once
#include "Object.h"
class Texture;
class Player : public Object
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void EnterCollision(Collider* _other) override;
private:
	const float defaultSpeed = 200;
	const float runningSpeed = 350;
	const float rpm = 600;
	const Vec2 boundary = Vec2(500, 500);
private:
	void Clamp();
	bool TryShoot();
	bool TryUltimite();
	void CreateProjectile();
	void CreateUltmite();
	Vec2 pivotPoint = Vec2(0, 0);
	float lastShotTime = 0;
	bool isSlow = false;
	Texture* m_pTex;
	Texture* m_pHitbox;
};

