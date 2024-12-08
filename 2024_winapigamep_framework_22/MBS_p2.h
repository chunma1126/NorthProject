#pragma once
#include "State.h"
class MBS_p2 : public State
{
public:
	MBS_p2(MidBoss* midboss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.19f;
	float m_timerFirst = 0;
	float m_timer = 0;
	Vec2 m_arr[18] = {
		{-1,1}, {-0.61f, 1.0f}, {-0.25f, 1.0f}, {-0.1, 1.0f}, {0.1f, 1.f}, {0.2f, 1.0f}, {0.3f, 1.0f}, {0.23f, 1.0f},{1, 1},
		{1, 1}, {0.6f, 1.2f}, {0.35f, 1.0f}, {0.2f, 1.0f}, {0, 1}, {-0.2f, 1.0f}, {-0.5f, 1.0f}, {-0.7f, 1.2f}, {-1,1 }
	};
	int m_cnt = 0;
};

