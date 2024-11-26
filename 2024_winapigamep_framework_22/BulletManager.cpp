#include "pch.h"
#include "BulletManager.h"
#include "Object.h"
#include "Projectile.h"
#include "FollowProjectile.h"
#include "TimeManager.h"

void BulletManager::Init()
{
#pragma region directionAndSpeed
    m_speeds[0] = 111.00f;
    m_direction[0] = 90.00f;
    m_speeds[1] = 133.10f;
    m_direction[1] = 98.70f;
    m_speeds[2] = 152.04f;
    m_direction[2] = 107.37f;
    m_speeds[3] = 166.88f;
    m_direction[3] = 116.18f;
    m_speeds[4] = 176.00f;
    m_direction[4] = 125.28f;
    m_speeds[5] = 181.88f;
    m_direction[5] = 134.29f;
    m_speeds[6] = 181.50f;
    m_direction[6] = 143.31f;
    m_speeds[7] = 175.54f;
    m_direction[7] = 152.33f;
    m_speeds[8] = 165.63f;
    m_direction[8] = 161.38f;
    m_speeds[9] = 151.50f;
    m_direction[9] = 170.43f;
    m_speeds[10] = 136.35f;
    m_direction[10] = 180.18f;
    m_speeds[11] = 120.40f;
    m_direction[11] = 190.90f;
    m_speeds[12] = 106.45f;
    m_direction[12] = 203.68f;
    m_speeds[13] = 98.56f;
    m_direction[13] = 219.22f;
    m_speeds[14] = 99.10f;
    m_direction[14] = 235.97f;
    m_speeds[15] = 107.97f;
    m_direction[15] = 251.19f;
    m_speeds[16] = 124.58f;
    m_direction[16] = 262.83f;
    m_speeds[17] = 133.10f;
    m_direction[17] = 81.30f;
    m_speeds[18] = 152.04f;
    m_direction[18] = 72.63f;
    m_speeds[19] = 166.88f;
    m_direction[19] = 63.82f;
    m_speeds[20] = 176.00f;
    m_direction[20] = 54.72f;
    m_speeds[21] = 181.88f;
    m_direction[21] = 45.71f;
    m_speeds[22] = 181.50f;
    m_direction[22] = 36.69f;
    m_speeds[23] = 175.54f;
    m_direction[23] = 27.67f;
    m_speeds[24] = 165.63f;
    m_direction[24] = 18.62f;
    m_speeds[25] = 151.50f;
    m_direction[25] = 9.57f;
    m_speeds[26] = 136.35f;
    m_direction[26] = 359.82f;
    m_speeds[27] = 120.40f;
    m_direction[27] = 349.10f;
    m_speeds[28] = 106.45f;
    m_direction[28] = 336.32f;
    m_speeds[29] = 98.56f;
    m_direction[29] = 320.78f;
    m_speeds[30] = 99.10f;
    m_direction[30] = 304.03f;
    m_speeds[31] = 107.97f;
    m_direction[31] = 288.81f;
    m_speeds[32] = 124.58f;
    m_direction[32] = 277.17f;
    m_speeds[33] = 147.85f;
    m_direction[33] = 270.05f;
#pragma endregion
}

void BulletManager::Update()
{
	if (m_isSpinShot)
	{
		if (m_spinEndTimer >= m_spinEndTime)
		{
			m_isSpinShot = false;
		}
		else 
		{
			ApplySpinShot();
		}
	}

    if (m_isRoseShot)
    {
        if (m_roseTimer >= m_roseEndTime)
        {
            m_isRoseShot = false;

            for (auto item : m_roseVec)
            {
                item->SetSpeed(m_roseShotInfo.bulletSpeed);
            }
            m_roseVec.clear();
        }
        else
        {
            ApplyRoseSpinShot();
        }
    }


}

void BulletManager::CircleShot(ShotInfo& _shotInfo)
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

void BulletManager::CircleShotGoToTarget(ShotInfo& _shotInfo, Object* _target , float changeTime)
{
	for (int i = 0; i < 360; i += _shotInfo.interval)
	{
		FollowProjectile* pObj = new FollowProjectile;

		pObj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		pObj->SetSize({ 400.f,400.f });
		pObj->SetSpeed(_shotInfo.bulletSpeed);
		pObj->SetChangeTime(changeTime);
		pObj->SetName(L"Projectile");
		pObj->SetTarget(_target);

		_shotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);

		float angle = i * (PI / 180.0f);
		pObj->SetDir({ cosf(angle), sinf(angle)});
	}
}

void BulletManager::SpinShot(ShotInfo& _shotInfo, float& spinAngle, float turnSpeed,float endTime)
{

	m_isSpinShot = true;
	m_spinShotInfo = _shotInfo;
	m_spinAngle = spinAngle;
	m_spinTurnSpeed = turnSpeed;
	m_spinEndTime = endTime;

}

void BulletManager::ApplySpinShot()
{
	m_spinShotTimer += fDT;
	if (m_spinShotTimer < m_spinShotInfo.interval) return;

	m_spinEndTimer += m_spinShotTimer;
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

void BulletManager::ShapeShot(ShotInfo& _shotInfo, Vec2 dir, int vertex, float size, float rotationSpeed)
{
    float angleIncrement = 360.0f / vertex;
    float radius = size;

    for (int i = 0; i < vertex; ++i)
    {
        float angleDegrees = i * angleIncrement;
        float angleRadians = angleDegrees * (M_PI / 180.0f);

        Projectile* pObj = new Projectile;

        float x = SCREEN_WIDTH / 2 + radius * cosf(angleRadians);
        float y = SCREEN_HEIGHT / 2 + radius * sinf(angleRadians);

        pObj->SetPos({ x, y });
        pObj->SetSize({ 400.f, 400.f });
        pObj->SetName(L"Projectile");
        pObj->SetDir(dir);
        pObj->SetSpeed(_shotInfo.bulletSpeed);

        _shotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);
    }
}


void BulletManager::HeartShot(ShotInfo& _shotInfo)
{
    for (int i = 0; i < 34; ++i)
    {
        Projectile* p = new Projectile;

        p->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
        p->SetSpeed(m_speeds[i] + _shotInfo.bulletSpeed);
        p->SetSize({200,200});

        float angleDegrees = m_direction[i] + m_heartRotation; 
        float angleRadians = angleDegrees * (M_PI / 180.0f); 

        float speed = m_speeds[i] / 50.0f;
        cout << speed << endl;

        float vx = cos(angleRadians) * speed;
        float vy = sin(angleRadians) * speed;

        p->SetDir({ vx, vy });

        _shotInfo.scene->AddObject(p,LAYER::PROJECTILE);
    }
}

void BulletManager::HeartShotGoToTarget(ShotInfo& _shotInfo, Object* target,float changeTime)
{
    for (int i = 0; i < 34; ++i)
    {
        FollowProjectile* p = new FollowProjectile;

        p->SetTarget(target);
        p->SetChangeTime(changeTime);
        p->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
        p->SetSpeed(m_speeds[i] + _shotInfo.bulletSpeed);
        p->SetSize({ 200,200 });

        float angleDegrees = m_direction[i] + m_heartRotation;
        float angleRadians = angleDegrees * (M_PI / 180.0f);

        float speed = m_speeds[i] / 50.0f;
        float vx = cos(angleRadians) * speed;
        float vy = sin(angleRadians) * speed;

        p->SetDir({ vx, vy });

        _shotInfo.scene->AddObject(p, LAYER::PROJECTILE);
    }
}

void BulletManager::HeartDataInit(float _rotation)
{
    m_heartRotation = _rotation;
}


void BulletManager::RoseShot(ShotInfo& _shotInfo, int petals, float size)
{
    int vertex = 360; 
    float k = static_cast<float>(petals); 

    for (int i = 0; i < vertex; ++i)
    {
        float angleDegrees = i; 
        float angleRadians = angleDegrees * (M_PI / 180.0f);

        float radius = size * sinf(k * angleRadians);

        Projectile* pObj = new Projectile;

        float x = SCREEN_WIDTH / 2 + radius * cosf(angleRadians);
        float y = SCREEN_HEIGHT / 2 + radius * sinf(angleRadians);

        pObj->SetPos({ x, y });
        pObj->SetSize({ 400.f, 400.f });
        pObj->SetName(L"Projectile");
        pObj->SetSpeed(_shotInfo.bulletSpeed);

        _shotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);
    }
}

void BulletManager::RoseSpinShot(ShotInfo& _shotInfo, Object* _target,int _petals, float _size, float _time)
{
    m_target = _target;
    m_isRoseShot = true;
    m_roseShotInfo = _shotInfo;
    m_roseEndTime = _time;
    m_roseSize = _size;
    m_rosePetals = _petals;

}

void BulletManager::ApplyRoseSpinShot()
{
    m_roseShotTimer += fDT;
    if (m_roseShotTimer < m_roseShotInfo.interval) return; 
    m_roseShotTimer = 0;

    int vertex = 360; 
    float k = static_cast<float>(m_rosePetals); 
    static int currentIndex = 0; 

    float angleDegrees = currentIndex;
    float angleRadians = angleDegrees * (M_PI / 180.0f);

    float radius =  m_roseSize * sinf(k * angleRadians);

    FollowProjectile* pObj = new FollowProjectile;
    pObj->SetChangeTime(m_roseEndTime);
    pObj->SetTarget(m_target);

    float x = SCREEN_WIDTH / 2 + radius * cosf(angleRadians);
    float y = SCREEN_HEIGHT / 2 + radius * sinf(angleRadians);

    pObj->SetPos({ x, y });
    pObj->SetSize({ 400.f, 400.f });
    pObj->SetName(L"Projectile");
    pObj->SetSpeed(0); 
    m_roseVec.push_back(pObj);


    m_roseShotInfo.scene->AddObject(pObj, LAYER::PROJECTILE);

    currentIndex = (currentIndex + 1) % vertex;
}

