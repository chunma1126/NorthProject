#include "pch.h"
#include "BulletManager.h"
#include "Object.h"
#include "Projectile.h"
#include "FollowProjectile.h"
#include "TimeManager.h"

void BulletManager::CircleShot(Scene* _scene, float _interval,float bulletSpeed)
{
	for (int i = 0; i < 360; i += _interval)
	{
		Projectile* pObj = new Projectile;
		pObj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		pObj->SetSize({ 400.f,400.f });
		pObj->SetSpeed(bulletSpeed);

		pObj->SetName(L"Projectile");
		_scene->AddObject(pObj, LAYER::PROJECTILE);

		float angle = i * (PI / 180.0f);
		pObj->SetDir({ cosf(angle), sinf(angle)});
	}
}

void BulletManager::CircleShotGoToTarget(Scene* _scene, float _interval, float _bulletSpeed, Object* _target)
{

	for (int i = 0; i < 360; i += _interval)
	{
		FollowProjectile* pObj = new FollowProjectile;

		pObj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		pObj->SetSize({ 400.f,400.f });
		pObj->SetSpeed(_bulletSpeed);
		pObj->SetChangeTime(1.3f);
		pObj->SetName(L"Projectile");
		pObj->SetTarget(_target);
		_scene->AddObject(pObj, LAYER::PROJECTILE);

		float angle = i * (PI / 180.0f);
		pObj->SetDir({ cosf(angle), sinf(angle)});
	}
}
