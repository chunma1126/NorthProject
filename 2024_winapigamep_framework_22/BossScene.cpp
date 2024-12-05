#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "CollisionManager.h";
#include "BulletManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "UIManager.h"
#include "Background.h"
#include "AllEnemies.h"
#include "Player.h"
#include "EnemyBullet.h"

void BossScene::Init()
{
	Background* b = new Background;
	AddObject(b, LAYER::BACKGROUND);

	m_player = new Player;
	AddObject(m_player, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart1", true);
	GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart2", true);
	GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart3", true);

	//DelayedCall* delayedCall0 = new DelayedCall(2.f, { {SCREEN_WIDTH * 0.2f , 0.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//DelayedCall* delayedCall1 = new DelayedCall(2.f, { {SCREEN_WIDTH * 0.8f , 0.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });

	DelayedCall* midBoss = new DelayedCall(0.f, { {SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f}, EnemyType::MidBoss, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });

	//GET_SINGLE(BulletManager)->HeartDataInit(270.f);
	//GET_SINGLE(BulletManager)->HeartShot(shotInfo);
	//
	//GET_SINGLE(BulletManager)->HeartDataInit(90.f);
	//GET_SINGLE(BulletManager)->HeartShotGoToTarget(shotInfo, m_player, 2.f);
	//
	//float angle = 0;
	//GET_SINGLE(BulletManager)->SpinShot(shotInfo_1, angle, 1200.f, 12);
	//
	//GET_SINGLE(BulletManager)->CircleShot(shotInfo);
	//
	//GET_SINGLE(BulletManager)->CircleShotGoToTarget(shotInfo, m_player, 1.2f);
	//Vec2 dir = {0, 1};
	//GET_SINGLE(BulletManager)->ShapeShot(shotInfo, dir, 3, 40,1.2f);
	//
	//GET_SINGLE(BulletManager)->RoseShot(shotInfo, {0,1}, 3, 300.f);
	//GET_SINGLE(BulletManager)->RoseSpinShot(shotInfo_1, m_player, 5,400.f ,5.f,20.f);
	//
	//GET_SINGLE(BulletManager)->BasicShot(shotInfo, {0,1});
	//GET_SINGLE(BulletManager)->ShapeShot(shotInfo, {0,1} , 3 , 40 , 10);*/
	//
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
}




