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

void BulletManager::HeartShot(ShotInfo _shotInfo)
{
    for (int i = 0; i < 34; ++i)
    {
        Projectile* p = new Projectile;

        p->SetPos({ 0, 0 });

        float rotation = _direction[i];
        float angleRadians = rotation * (M_PI / 180.0f); 

        float speed = _speeds[i] / 50.0f;
        float vx = cos(angleRadians) * speed;
        float vy = sin(angleRadians) * speed;

        p->SetDir({ vx, vy });
        int intp = p->GetPos().x;
        cout << intp << endl;
    }
}

void BulletManager::HeartDataInit()
{
    _speeds[0] = 111.00f;
    _direction[0] = 90.00f;
    _speeds[1] = 133.10f;
    _direction[1] = 98.70f;
    _speeds[2] = 152.04f;
    _direction[2] = 107.37f;
    _speeds[3] = 166.88f;
    _direction[3] = 116.18f;
    _speeds[4] = 176.00f;
    _direction[4] = 125.28f;
    _speeds[5] = 181.88f;
    _direction[5] = 134.29f;
    _speeds[6] = 181.50f;
    _direction[6] = 143.31f;
    _speeds[7] = 175.54f;
    _direction[7] = 152.33f;
    _speeds[8] = 165.63f;
    _direction[8] = 161.38f;
    _speeds[9] = 151.50f;
    _direction[9] = 170.43f;
    _speeds[10] = 136.35f;
    _direction[10] = 180.18f;
    _speeds[11] = 120.40f;
    _direction[11] = 190.90f;
    _speeds[12] = 106.45f;
    _direction[12] = 203.68f;
    _speeds[13] = 98.56f;
    _direction[13] = 219.22f;
    _speeds[14] = 99.10f;
    _direction[14] = 235.97f;
    _speeds[15] = 107.97f;
    _direction[15] = 251.19f;
    _speeds[16] = 124.58f;
    _direction[16] = 262.83f;
    _speeds[17] = 133.10f;
    _direction[17] = 81.30f;
    _speeds[18] = 152.04f;
    _direction[18] = 72.63f;
    _speeds[19] = 166.88f;
    _direction[19] = 63.82f;
    _speeds[20] = 176.00f;
    _direction[20] = 54.72f;
    _speeds[21] = 181.88f;
    _direction[21] = 45.71f;
    _speeds[22] = 181.50f;
    _direction[22] = 36.69f;
    _speeds[23] = 175.54f;
    _direction[23] = 27.67f;
    _speeds[24] = 165.63f;
    _direction[24] = 18.62f;
    _speeds[25] = 151.50f;
    _direction[25] = 9.57f;
    _speeds[26] = 136.35f;
    _direction[26] = 359.82f;
    _speeds[27] = 120.40f;
    _direction[27] = 349.10f;
    _speeds[28] = 106.45f;
    _direction[28] = 336.32f;
    _speeds[29] = 98.56f;
    _direction[29] = 320.78f;
    _speeds[30] = 99.10f;
    _direction[30] = 304.03f;
    _speeds[31] = 107.97f;
    _direction[31] = 288.81f;
    _speeds[32] = 124.58f;
    _direction[32] = 277.17f;
    _speeds[33] = 147.85f;
    _direction[33] = 270.05f;
}

