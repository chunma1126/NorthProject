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
	const float m_shotTime = 0.03f;
	float m_timer = 0;
	const float m_moveTime = 0.7f;
	float m_moveTimer = 0;
	Vec2 m_arrPos[3] = {
		{SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.1f},
		{SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f},
		{SCREEN_WIDTH * 0.6f, SCREEN_HEIGHT * 0.1f}
	};
	Vec2 m_targetPos = m_arrPos[0];
	float m_timerFirst = 0;
	Object* m_player;
};

