#pragma once
#include "Enemy.h"
class Texture;
class TrashMob1 : public Enemy
{
public:
	TrashMob1(const wstring& _key, const wstring& _path);
	~TrashMob1();
public:
	void Update() override;

private:

};

