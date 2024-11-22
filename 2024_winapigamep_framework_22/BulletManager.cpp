#include "pch.h"
#include "BulletManager.h"
#include "Object.h"
#include "Projectile.h"
#include "FollowProjectile.h"
#include "TimeManager.h"

void BulletManager::Update()
{
	if (m_isSpinShot)
	{
		if (m_endTimer >= m_endTime)
		{
			m_isSpinShot = false;
		}
		else 
		{
			ApplySpinShot();
		}
	}


}

void BulletManager::CircleShot(ShotInfo _shotInfo)
{
	for (int i = 0; i < 360; i += _shotInfo.interval)
	{
		Projectile* pObj = new Projectile;
		pObj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		pObj->SetSize({ 400.f,400.f });
		pObj->SetSpeed(_shotInfo.bulletSpeed);

		pObj->SetName(L"Projectile");
		_shotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);

		float angle = i * (PI / 180.0f);
		pObj->SetDir({ cosf(angle), sinf(angle)});
	}
}

void BulletManager::CircleShotGoToTarget(ShotInfo _shotInfo, Object* _target)
{
	for (int i = 0; i < 360; i += _shotInfo.interval)
	{
		FollowProjectile* pObj = new FollowProjectile;

		pObj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		pObj->SetSize({ 400.f,400.f });
		pObj->SetSpeed(_shotInfo.bulletSpeed);
		pObj->SetChangeTime(1.3f);
		pObj->SetName(L"Projectile");
		pObj->SetTarget(_target);


		_shotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);

		float angle = i * (PI / 180.0f);
		pObj->SetDir({ cosf(angle), sinf(angle)});
	}
}

void BulletManager::SpinShot(ShotInfo _shotInfo, float& spinAngle, float turnSpeed,float endTime)
{

	m_isSpinShot = true;
	m_spinShotInfo = _shotInfo;
	m_spinAngle = spinAngle;
	m_spinTurnSpeed = turnSpeed;
	m_endTime = endTime;

}

void BulletManager::ApplySpinShot()
{
	m_spinShotTimer += fDT;
	if (m_spinShotTimer < m_spinShotInfo.interval) return;

	m_endTimer += m_spinShotTimer;
	m_spinShotTimer = 0.0f;

	m_spinAngle += m_spinTurnSpeed * fDT;
	if (m_spinAngle >= 360.0f) m_spinAngle -= 360.0f;

	float angleInRadians = m_spinAngle * (PI / 180.0f);

	Projectile* pObj = new Projectile;

	pObj->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	pObj->SetSize({ 400.f, 400.f });
	pObj->SetSpeed(m_spinShotInfo.bulletSpeed);

	Vec2 dir = { cosf(angleInRadians), sinf(angleInRadians) };
	pObj->SetDir(dir);

	m_spinShotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);
}

void BulletManager::ShapeShot(ShotInfo _shotInfo, int _m, int _a, float _phi)
{

}

