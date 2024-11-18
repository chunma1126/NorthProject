#include "pch.h"
#include "OJYScene.h"
#include "Enemy.h"
#include "Player.h"
#include "CollisionManager.h"

void OJYScene::Init()
{
	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f, 150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Enemy");
	AddObject(pObj, LAYER::ENEMY);

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 2.f / 3.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);

	//sound
	//GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->Play(L"BGM");
}