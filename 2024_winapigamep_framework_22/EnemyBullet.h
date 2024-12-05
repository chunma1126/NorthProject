#pragma once
#include "Projectile.h"
class EnemyBullet : public Projectile
{
public:
	EnemyBullet();
	~EnemyBullet();

	//void Update() override;

	void Render(HDC _hdc) override;


};

