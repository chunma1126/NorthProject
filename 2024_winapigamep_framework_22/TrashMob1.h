#pragma once
#include "Enemy.h"
#include "BulletManager.h"
class TrashMob1 : public Enemy
{
public:
	TrashMob1(const wstring& _key, const wstring& _path);
	~TrashMob1();
	void Update() override;
	

};

