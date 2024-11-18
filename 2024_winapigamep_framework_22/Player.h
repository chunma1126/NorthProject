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
private:
	const float defaultSpeed = 300;
	const float runningSpeed = 200;
	const float rpm = 100;
private:
	bool TryShoot();
	void CreateProjectile();
	void CreateUltmite();
	float lastShotTime = 0;
	bool isSlow = false;
	Texture* m_pTex;
	Texture* m_pWomb;
};

