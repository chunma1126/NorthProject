#pragma once
#include "Enemy.h"
class MidBoss : public Enemy
{
public:
	MidBoss(const wstring& _key, const wstring& _path);
	~MidBoss();
	void Update() override;
private:
	const float m_shotTime = 0.5f;
private:
	float m_timer = 0;
	int cnt = 0;
	float arr[5] = { 60, 25, 30, 25, 60 };

	float stayTime = 3.f;
	float stayTimer = 0;
};

