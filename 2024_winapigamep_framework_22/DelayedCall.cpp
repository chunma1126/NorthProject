#include "pch.h"
#include "DelayedCall.h"
#include "TimeManager.h"
#include "EnemySpawnEventManager.h"
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
	cout << m_spawnStruct.position.x;
}
