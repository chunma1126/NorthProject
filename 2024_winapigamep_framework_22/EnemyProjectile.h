#pragma once
#include "Projectile.h"
class EnemyProjectile : public Projectile
{
public:
	EnemyProjectile();
	~EnemyProjectile();

	//void Update() override;

	void Render(HDC _hdc) override;


};

