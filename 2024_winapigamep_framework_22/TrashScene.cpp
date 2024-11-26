#include "pch.h"
#include "TrashScene.h"
#include "Enemy.h"
#include "TrashMob1.h"

void TrashScene::Init()
{
	Object* tr[10];
	for (int i = 0; i < 10; i++) {
		tr[i] = new TrashMob1;
	}
	
	tr[0]->SetPos(enemyPos3);
	tr[0]->SetSize({ 100.f,100.f });
	tr[0]->SetName(L"TrashMob1");
	AddObject(tr[0], LAYER::ENEMY);

	tr[1]->SetPos(enemyPos1);
	tr[1]->SetSize({ 100.f,100.f });
	tr[1]->SetName(L"TrashMob1");
	AddObject(tr[1], LAYER::ENEMY);

	tr[2]->SetPos(enemyPos2);
	tr[2]->SetSize({ 100.f,100.f });
	tr[2]->SetName(L"TrashMob1");
	AddObject(tr[2], LAYER::ENEMY);




}

