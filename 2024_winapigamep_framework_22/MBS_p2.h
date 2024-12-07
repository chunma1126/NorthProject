#pragma once
#include "State.h"
class MBS_p2 : public State
{
public:
	MBS_p2(MidBoss* midboss);
public:
	void Update() override;
private:
	const float m_shotTime = 0.19f;
	float m_timer = 0;
	Vec2 m_arr[14] = {
		{-1,1}, {-0.7f, 1.0f}, {-0.4, 1.0f}, {0, 1}, {0.4f, 1.0f}, {0.7f, 1.0f},{1, 1},
		{1, 1}, {0.7f, 1.2f}, {0.3f, 1.0f}, {0, 1}, {-0.3f, 1.0f}, {-0.7f, 1.2f}, {-1,1 }
	};
	int m_cnt = 0;
};

