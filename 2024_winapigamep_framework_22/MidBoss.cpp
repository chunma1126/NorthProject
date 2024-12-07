#include "pch.h"
#include "MidBoss.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
MidBoss::MidBoss(const wstring& _key, const wstring& _path)
	: Enemy(_key, _path)
{
	m_stateMachine = new StateMachine();
}

MidBoss::~MidBoss()
{
}

void MidBoss::Update()
{
	Enemy::Update();
	Vec2 curPos = GetPos();
	m_stateMachine->UpdateState();

	//states

	m_timer += fDT;
	if (m_timer >= m_shotTime)
	{
		m_stateMachine->ChangeState(MidBossState::p2);
		m_timer = 0;
		//Shot();
	}
}
void MidBoss::Shot()
{
	m_timer = 0;
	int idx = cnt % 5;
	float angle = arr[idx];
	cnt++;
	GET_SINGLE(BulletManager)->CircleShot({ GetPos().x ,GetPos().y + 50 }, m_curScene, angle, 400);
}
