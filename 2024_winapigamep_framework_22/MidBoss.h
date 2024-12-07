#pragma once
#include "Enemy.h"
class StateMachine;
class MidBoss : public Enemy
{
public:
	MidBoss(const wstring& _key, const wstring& _path);
	~MidBoss();
	void Update() override;
private:
	void Shot();
private:
	const float m_shotTime = 0.5f;
private:
	StateMachine* m_stateMachine = nullptr;
private:
	bool allowShot = false;
#pragma region p1
	float stayTime = 3.f;
	float stayTimer = 0;
#pragma endregion
	float m_timer = 0;
	int cnt = 0;
	float arr[5] = { 60, 25, 30, 25, 60 };
};

