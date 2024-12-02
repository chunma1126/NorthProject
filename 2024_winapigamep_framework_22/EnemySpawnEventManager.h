#pragma once
#include "pch.h"
class DelayedCall;
class EnemySpawnEventManager
{
	DECLARE_SINGLE(EnemySpawnEventManager)
public:
	void Update();
	void AddDelayedCall(DelayedCall* pDelayedCall);
private:
	vector<DelayedCall*> m_delayedCalls;
};

