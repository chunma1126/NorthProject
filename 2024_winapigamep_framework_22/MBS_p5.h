#pragma once
#include "State.h"
class MBS_p5 : public State
{
public:
	MBS_p5(MidBoss* midboss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.11f;
	float m_angle = 0;
	float m_timer = 0;
	float m_timerFirst = 0;
};

