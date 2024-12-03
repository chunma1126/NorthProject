#pragma once
#include "Projectile.h"
class EnemyBullet : public Projectile
{
public:
	EnemyBullet();
	~EnemyBullet();

	void Render(HDC _hdc) override;


};

