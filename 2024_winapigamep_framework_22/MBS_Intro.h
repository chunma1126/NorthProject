#pragma once
#include "State.h"
class MBS_Intro : public State
{
public:
	MBS_Intro(MidBoss* midBoss);
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
private:
	Vec2 m_targetPos = Vec2({ SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f });
	//const float m_shotTime = 0.5f;
	float m_timer = 0;
	//float m_arr[8] = { 7, 6, 5, 6, 5, 6, 6, 4 };
	//int m_cnt = 0;
};

