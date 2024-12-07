#include "pch.h"
#include "MBS_p1.h"
MBS_p1::MBS_p1(MidBoss* midBoss)
	: State(midBoss)
{
	stateEndTime = 0;
}

void MBS_p1::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	m_StateTimer += dt;
	if (m_StateTimer < stateEndTime)
	{
		m_timer += dt;
		if (m_timer > m_shotTime)
		{
			m_timer = 0;
			int idx = m_cnt % 6;
			float angle = m_arr[idx];
			Vec2 pos = m_midBoss->GetPos();
			GET_SINGLE(BulletManager)->CircleShot({ pos.x ,pos.y + 10 }, m_midBoss->GetCurrentScene(), angle, 400);
			m_cnt++;
		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p2);
	}
}