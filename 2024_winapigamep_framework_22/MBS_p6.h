#pragma once
#include "State.h"
class MBS_p6 : public State
{
public:
	MBS_p6(MidBoss* midBoss);
public:
	void Enter() override;
	void Update() override;
private:
	const float m_shotTime = 0.71f;
	float m_timer = 0;
	int m_arr[3]{ 3,6,1 };
	float m_arrSize[3]{ 40,60,160 };
	int cnt = 0;
	Object* m_player;

};

