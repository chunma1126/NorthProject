#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "Projectile.h"

void BossScene::Init()
{
	Object* pObj = new Projectile;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Projectile");
	AddObject(pObj, LAYER::PROJECTILE);





}


