#include "pch.h"
#include "MBS_p5.h"

MBS_p5::MBS_p5(MidBoss* midboss)
	: State(midboss)
{
	stateEndTime = 20;
}

void MBS_p5::Enter()
{
	m_StateTimer = 0;
	m_timerFirst = 0;
	m_timer = 0;
	Vec2 pos = m_midBoss->GetPos();
	GET_SINGLE(BulletManager)->SpinShot(pos, m_midBoss->GetCurrentScene(), 0.01, 500, m_angle, 500, 20);
}

void MBS_p5::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	m_timer += dt;
	if (m_StateTimer < stateEndTime)
	{
		//m_timerFirst += dt;
		//const float timerFirstEndTime = 0;
		//bool allowShot = m_timerFirst > timerFirstEndTime;
		//if (allowShot) {
		//	m_timer += dt;
		//	if (m_timer > m_shotTime)
		//	{
		//		m_timer = 0;
		//		Vec2 dir = Vec2(0, 1);
		//	}
		//}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p1);
	}
}