#pragma once
#include "State.h"
class MBS_p1 : public State
{
public:
	MBS_p1(MidBoss* midBoss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.33f;
	float m_timer = 0;
	float m_arr[8] = { 7, 6, 5, 6, 5, 6, 6, 3 };
	int m_cnt = 0;
};

