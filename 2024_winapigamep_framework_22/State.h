#pragma once
#include "MidBoss.h"
#include "BulletManager.h"
#include "TimeManager.h"
class State
{
public:
	State(MidBoss* midboss);
	~State();
public:
	virtual void Enter();
	virtual void Update();
	virtual void Exit();
protected:
#pragma region State
	float stateEndTime = 0;
	float m_StateTimer = 0;
#pragma endregion
	MidBoss* m_midBoss;
};

