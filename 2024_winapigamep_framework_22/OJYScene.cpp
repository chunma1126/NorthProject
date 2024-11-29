#include "pch.h"
#include "OJYScene.h"
#include "Enemy.h"
#include "Player.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "Projectile.h"
void OJYScene::Init()
{
	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f, 150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Enemy");
	AddObject(pObj, LAYER::ENEMY);

	Projectile* pEnemyProj = new Projectile(L"EnemyBullet", L"Texture\\Heart.bmp");
	pEnemyProj->SetPos({ SCREEN_WIDTH / 2.f, 200.f });
	pEnemyProj->SetSize({ 30.f,30.f });
	pEnemyProj->SetSpeed(30);
	pEnemyProj->SetTag(TagEnum::EnemyProjectile);
	AddObject(pEnemyProj, LAYER::PROJECTILE);

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