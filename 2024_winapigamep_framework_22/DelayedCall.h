#pragma once
#include "Enemy.h"
struct tEnemySpawnStruct {
public:
	Vec2 position;
};
class DelayedCall
{
public:
	DelayedCall(float value, const tEnemySpawnStruct& spawnStruct);
	~DelayedCall();
public:
	void OnFinish();
	const float& GetEndTime() { return m_endTime; }
private:
	const tEnemySpawnStruct m_spawnStruct;
	float m_endTime;
};
