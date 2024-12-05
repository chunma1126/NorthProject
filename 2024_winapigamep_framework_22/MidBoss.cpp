#include "pch.h"
#include "MidBoss.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
MidBoss::MidBoss(const wstring& _key, const wstring& _path)
	: Enemy(_key, _path)
{
}

MidBoss::~MidBoss()
{
}

void MidBoss::Update()
{
	Enemy::Update();

	Vec2 curPos = GetPos();

	if (curPos.y > SCREEN_HEIGHT / 2)
	{
		stayTimer += fDT;

		if (stayTimer >= stayTime)
		{
			dirRight = curPos.x < SCREEN_WIDTH / 2 ? false : true;

			if (dirRight)
			{
				curPos.x += 100 * fDT;
			}
			else
			{
				curPos.x -= 100 * fDT;
			}
		}
	}
	else
	{
		curPos.y += 100 * fDT;
		SetPos(curPos);
	}

	m_timer += fDT;

	if (m_timer >= m_shotTime)
	{
		m_timer = 0;
		int idx = cnt % 5;
		float angle = arr[idx];
		cnt++;
		GET_SINGLE(BulletManager)->CircleShot({ GetPos().x ,GetPos().y + 50 }, m_curScene, angle, 400);
	}
}
