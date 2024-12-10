#pragma once
#include "State.h"
class MBS_p3 : public State
{
public:
	MBS_p3(MidBoss* midboss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.045f;
	float m_timer = 0;
	const float m_moveTime = 0.8f;
	float m_moveTimer = 0;
	Vec2 m_arrPos[3] = {
		{SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.1f},
		{SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f},
		{SCREEN_WIDTH * 0.9f, SCREEN_HEIGHT * 0.1f}
	};
	float m_timerFirst = 0;
	Object* m_player;
};

