#include "pch.h"
#include "MBS_p4.h"

MBS_p4::MBS_p4(MidBoss* midboss)
	: State(midboss)
{
	stateEndTime = 10;
}

void MBS_p4::Enter()
{
	m_midBoss->SetPos({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f });
	m_StateTimer = 0;
	m_timer = 0;
	m_timerFirst = 0;
	GET_SINGLE(BulletManager)->HeartDataInit(180);
}

void MBS_p4::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	if (m_StateTimer < stateEndTime)
	{
		m_timerFirst += dt;
		m_StateTimer += dt;
		const float timerFirstEndTime = 0;
		bool allowShot = m_timerFirst > timerFirstEndTime;
		if (allowShot) {
			m_timer += dt;
			if (m_timer > m_shotTime)
			{
				if (m_player == nullptr)
				{
					vector<Object*> player = m_midBoss->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
					m_player = player[0];
				}
				m_timer = 0;
				Vec2 pos = m_midBoss->GetPos();
				Vec2 dir = Vec2(0, 1);
				//GET_SINGLE(BulletManager)->HeartShotGoToTarget(pos, m_midBoss->GetCurrentScene(), 100, m_player, 100);
				GET_SINGLE(BulletManager)->HeartShotGoToTarget(pos, m_midBoss->GetCurrentScene(), 40, m_player, 1.f);
			}
		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p5);
	}
}
