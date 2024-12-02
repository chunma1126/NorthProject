#include "pch.h"
#include "EnemySpawnEventManager.h"
#include "DelayedCall.h"
#include "TimeManager.h"
void EnemySpawnEventManager::Update()
{
	const float& currentTime = GET_SINGLE(TimeManager)->GetTime();
	
	for (int i = 0; i < m_delayedCalls.size(); i++)
	{
		auto& element = m_delayedCalls[i];
		if (element->GetEndTime() < currentTime)
		{
			element->OnFinish();
			m_delayedCalls.erase(m_delayedCalls.begin(), m_delayedCalls.begin() + i);
		}
	}
}

void EnemySpawnEventManager::AddDelayedCall(DelayedCall* pDelayedCall)
{
	m_delayedCalls.push_back(pDelayedCall);
}
