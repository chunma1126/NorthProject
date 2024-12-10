#pragma once
#include "State.h"
class MBS_p4 : public State
{
public:
	MBS_p4(MidBoss* midboss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.65f;
	float m_timer = 0;
	float m_timerFirst = 0;
	Object* m_player;
};

