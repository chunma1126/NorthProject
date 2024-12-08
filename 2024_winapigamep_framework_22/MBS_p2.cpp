#include "pch.h"
#include "MBS_p2.h"

MBS_p2::MBS_p2(MidBoss* midboss)
	: State(midboss)
{
	stateEndTime = 20;
	//m_midBoss->SetPos({ SCREEN_WIDTH * 0.0f , SCREEN_HEIGHT * 0.f });
}

void MBS_p2::Enter()
{
	m_StateTimer = 0;
	m_timerFirst = 0;
	m_timer = 0; 
	m_cnt = 0;
}

void MBS_p2::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	m_StateTimer += dt;
	if (m_StateTimer < stateEndTime)
	{
		m_timerFirst += dt;
		const float timerFirstEndTime = 1.9;
		bool allowShot = m_timerFirst > timerFirstEndTime;
		if (allowShot) {
			m_timer += dt;
			if (m_timer > m_shotTime)
			{
				m_timer = 0;
				int idx = m_cnt % 18;
				Vec2 dir = m_arr[idx];
				Vec2 pos = m_midBoss->GetPos();
				pos.y = SCREEN_HEIGHT * 0.3f;
				GET_SINGLE(BulletManager)->ShapeShot(pos, m_midBoss->GetCurrentScene(), 820, dir, 20, 50, 100);
				m_cnt++;
			}
		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p3);
	}
}

