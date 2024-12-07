#pragma once
#include "Enemy.h"
#include "TimeManager.h"
class TrashMob3 : public Enemy
{
public:
	TrashMob3(const wstring& _key, const wstring& _path);
	void Update() override;
private:
	float m_angle = 0.0f;
	float m_radius = 200.f;
	Vec2 m_center;
	Object* m_player;

};

