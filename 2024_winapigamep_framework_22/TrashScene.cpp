#include "pch.h"
#include "TrashScene.h"
#include "Enemy.h"
#include "TrashMob1.h"

void TrashScene::Init()
{
	Object* pObj = new TrashMob1;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"TrashMob1");
	AddObject(pObj, LAYER::ENEMY);




}

void TrashScene::Update()
{

}
