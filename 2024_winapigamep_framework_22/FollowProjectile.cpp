#include "pch.h"
#include "FollowProjectile.h"
#include "EventManager.h"
#include "TimeManager.h"

void FollowProjectile::Update()
{
	m_changeTimer += fDT;

	if (m_changeTimer >= m_followChangeTime && m_isFollowing == false)
	{
		m_isFollowing = true;

		cout << m_isFollowing << endl;

		Vec2 vPos = GetPos();
		Vec2 targetPos = m_target->GetPos();

		m_targetDir = targetPos - vPos;
	}

	if (m_isFollowing)
	{
		Vec2 vPos = GetPos();


		m_targetDir.Normalize();

		vPos.x += m_targetDir.x * m_speed * 1.5f * fDT;
		vPos.y += m_targetDir.y * m_speed * 1.5f * fDT;

		SetPos(vPos);
	}
	else
	{
		Vec2 vPos = GetPos();
		vPos.x += m_vDir.x * m_speed * fDT;
		vPos.y += m_vDir.y * m_speed * fDT;
		SetPos(vPos);
		Vec2 vSize = GetSize();
		if (vPos.y < -vSize.y)
		{
			GET_SINGLE(EventManager)->DeleteObject(this);
		}
	}

	cout << m_isFollowing << endl;

}
