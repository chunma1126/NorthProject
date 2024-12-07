#include "pch.h"
#include "MBS_p2.h"

MBS_p2::MBS_p2(MidBoss* midboss)
	: State(midboss)
{
	stateEndTime = 20;
	m_midBoss->SetPos({ SCREEN_WIDTH * 0.0f , SCREEN_HEIGHT * 0.f });
}

void MBS_p2::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	m_StateTimer += dt;
	if (m_StateTimer < stateEndTime)
	{
		m_timer += dt;
		if (m_timer > m_shotTime)
		{
			m_timer = 0;
			int idx = m_cnt % 14;
			Vec2 dir = m_arr[idx];
			Vec2 pos = m_midBoss->GetPos();
			GET_SINGLE(BulletManager)->ShapeShot(pos, m_midBoss->GetCurrentScene(), 500, dir, 30, 50, 100);
			m_cnt++;
		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p2);
	}
}
