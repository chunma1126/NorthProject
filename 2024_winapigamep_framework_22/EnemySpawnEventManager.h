#pragma once
class DelayedCall;
class EnemySpawnEventManager
{
	DECLARE_SINGLE(EnemySpawnEventManager)
public:
	void Update();
	void AddDelayedCall(DelayedCall* pDelayedCall);
	void Release();
	void Clear() { m_delayedCalls.clear(); }
private:
	vector<DelayedCall*> m_delayedCalls;
};

