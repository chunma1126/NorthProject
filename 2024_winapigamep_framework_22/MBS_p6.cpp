#include "pch.h"
#include "MBS_p6.h"

MBS_p6::MBS_p6(MidBoss* midBoss)
	: State(midBoss)
{
	stateEndTime = 20;
}

void MBS_p6::Enter()
{
	m_StateTimer = 0;
	m_timer = 0;
	cnt = 0;
	if (m_player == nullptr)
	{
		vector<Object*> player = m_midBoss->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
		m_player = player[0];
	}
	GET_SINGLE(BulletManager)->RoseSpinShot({}, m_midBoss->GetCurrentScene(), 0.01f, 100, m_player, 30, 30, 2, 30);
}

void MBS_p6::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	m_StateTimer += dt;
	if (m_StateTimer < stateEndTime)
	{
		m_timer += dt;
		if (m_timer > m_shotTime)
		{
			m_timer = 0;
			if (m_player == nullptr)
			{
				vector<Object*> player = m_midBoss->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
				m_player = player[0];
			}
			Vec2 dir = Vec2(0, 1);//m_arr[idx];
			Vec2 pos = m_midBoss->GetPos();
			//pos.y = SCREEN_HEIGHT * 0.20f;
			//pos.x += 10;
			if (m_player != nullptr)
			{
				Vec2 playerPos = m_player->GetPos();
				dir = playerPos - pos;
			}
			int petals = m_arr[cnt % 3];
			GET_SINGLE(BulletManager)->RoseShot(m_midBoss->GetCurrentScene(), 10, 800, dir, petals, 100);
			cnt++;
		}
	}
	else {
		m_midBoss->ChangeState(MidBossState::p1);
	}
}
