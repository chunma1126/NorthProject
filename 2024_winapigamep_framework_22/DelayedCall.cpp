#include "pch.h"
#include "DelayedCall.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "EnemySpawnEventManager.h"
#include "Scene.h"
#include "AllEnemies.h"
DelayedCall::DelayedCall(float value, const tEnemySpawnStruct& spawnStruct)
	: m_endTime(value + GET_SINGLE(TimeManager)->GetTime())
	, m_spawnStruct(spawnStruct)
{
	GET_SINGLE(EnemySpawnEventManager)->AddDelayedCall(this);
}
DelayedCall::~DelayedCall()
{
}
void DelayedCall::OnFinish()
{
	EnemyType enemyType = m_spawnStruct.enemyType;
	Object* pObj = nullptr;
	switch (enemyType)
	{
	case EnemyType::Normal:
		pObj = new Enemy(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::CircleOut:
		pObj = new EnemyCircleOut(m_spawnStruct.key, m_spawnStruct.path);
		break;
	}
	pObj->SetPos({ m_spawnStruct.position.x, m_spawnStruct.position.y });
	pObj->SetSize({ 100.f,100.f });
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pObj, LAYER::ENEMY);
}
