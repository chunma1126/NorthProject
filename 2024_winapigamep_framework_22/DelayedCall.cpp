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
	Enemy* pObj = nullptr;
	switch (enemyType)
	{
	case EnemyType::Normal:
		pObj = new Enemy(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::CircleOut:
		pObj = new EnemyCircleOut(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::TrashMob1:
		pObj = new TrashMob1(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::TrashMob2:
		pObj = new TrashMob2(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::TrashMob3:
		pObj = new TrashMob3(m_spawnStruct.key, m_spawnStruct.path);
		break;
	case EnemyType::MidBoss:
		pObj = new MidBoss(m_spawnStruct.key, m_spawnStruct.path);
		break;
	}
	if (pObj == nullptr)
	{
		cout << "\nfailed to spawn Enemy" << (int)enemyType;
		return;
	}
	if(m_spawnStruct.hp != 0)
		pObj->SetHP(m_spawnStruct.hp);
	pObj->SetScene(GET_SINGLE(SceneManager)->GetCurrentScene().get());
	pObj->SetPos({ m_spawnStruct.position.x, m_spawnStruct.position.y });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetTag(TagEnum::Enemy);
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pObj, LAYER::ENEMY);

}
