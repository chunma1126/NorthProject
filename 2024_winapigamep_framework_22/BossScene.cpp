#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "Player.h"

void BossScene::Init()
{
	Object* pObj = new Player;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Player");
	AddObject(pObj, LAYER::PLAYER);




}

void BossScene::Update()
{

}
