#include "pch.h"
#include "MBS_p3.h"
MBS_p3::MBS_p3(MidBoss* midboss)
	: State(midboss)
	, m_player(nullptr)
{
	stateEndTime = 4.8;
}

void MBS_p3::Enter()
{
	m_StateTimer = 0;
	m_timerFirst = 0;
	m_timer = 0;
	m_moveTimer = 0;
}

void MBS_p3::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	if (m_StateTimer < stateEndTime)
	{
		m_timerFirst += dt;
		m_StateTimer += dt;
		const float timerFirstEndTime = 0;
		bool allowShot = m_timerFirst > timerFirstEndTime;
		if (allowShot) {
			Vec2 pos = m_midBoss->GetPos();
			Vec2 dir = m_targetPos - pos;
			dir.y = 0;
			dir.Normalize();
			dir.x *= 5;
			Vec2 result = pos + dir;
			float dt = GET_SINGLE(TimeManager)->GetDT();
			m_midBoss->SetPos(Vec2::MoveTowards(pos, m_targetPos, 300 * dt));
			//m_midBoss->SetPos(result);
			if (m_player == nullptr)
			{
				vector<Object*> player = m_midBoss->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
				m_player = player[0];
			}
			m_timer += dt;
			m_moveTimer += dt;
			if (m_timer > m_shotTime)
			{
				m_timer = 0;
				Vec2 pos = m_midBoss->GetPos();
				Vec2 dir = Vec2(0, 1);
				if (m_player != nullptr)
				{
					Vec2 playerPos = m_player->GetPos();
					Vec2 resultDir = playerPos - pos;
					dir = resultDir;
				}
				GET_SINGLE(BulletManager)->BasicShot(pos, m_midBoss->GetCurrentScene(), 800, dir);
			}
			if (m_moveTimer > m_moveTime) {
				m_moveTimer = 0;
				m_timer = -0.2f;
				Vec2 randPos = m_arrPos[rand() % 3];
				m_targetPos = randPos;
				//m_midBoss->SetPos(randPos);
			}

		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p4);
	}
}
