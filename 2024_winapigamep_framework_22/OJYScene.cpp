#include "pch.h"
#include "OJYScene.h"
#include "Player.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "Projectile.h"
#include "AllEnemies.h"
#include "DelayedCall.h"
void OJYScene::Init()
{
	//DelayedCall* d = new DelayedCall(2.f, { 1 });
	
	Object* pObj = new EnemyCircleOut(L"EnemyCircleOut", L"Texture\\Heart.bmp");
	pObj->SetPos({ SCREEN_WIDTH / 2.f, 150.f });
	pObj->SetSize({ 100.f,100.f });
	AddObject(pObj, LAYER::ENEMY);

	//Projectile* pEnemyProj = new Projectile(L"EnemyBullet", L"Texture\\Heart.bmp");
	//pEnemyProj->SetPos({ SCREEN_WIDTH / 2.f, 200.f });
	//pEnemyProj->SetSize({ 30.f,30.f });
	//pEnemyProj->SetSpeed(30);
	//pEnemyProj->SetTag(TagEnum::EnemyProjectile);
	//AddObject(pEnemyProj, LAYER::PROJECTILE);

	//Projectile* pEnemyProj2 = new Projectile(L"EnemyBullet", L"Texture\\Heart.bmp");
	//pEnemyProj2->SetPos({ SCREEN_WIDTH / 2.f, 250.f });
	//pEnemyProj2->SetSize({ 30.f,30.f });
	//pEnemyProj2->SetSpeed(350);
	//pEnemyProj2->SetTag(TagEnum::EnemyProjectile);
	//AddObject(pEnemyProj2, LAYER::PROJECTILE);

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 2.f / 3.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);

	GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->PlayAudio(L"BGM");
}
