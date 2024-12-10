#include "pch.h"
#include "MBS_Intro.h"

MBS_Intro::MBS_Intro(MidBoss* midBoss)
	: State(midBoss)
{
	stateEndTime = 3.75f;
}

void MBS_Intro::Enter()
{
	m_timer = 0;
	m_midBoss->SetGodMode(true);
}

void MBS_Intro::Update()
{
	Vec2 pos = m_midBoss->GetPos();
	float dt = fDT;
	m_midBoss->SetPos(Vec2::MoveTowards(pos, m_targetPos, 150 * dt));
	m_timer += fDT;
	if (m_timer >= stateEndTime) {
		m_midBoss->ChangeState(MidBossState::p1);
	}
}

void MBS_Intro::Exit()
{
	m_midBoss->SetGodMode(false);
}
