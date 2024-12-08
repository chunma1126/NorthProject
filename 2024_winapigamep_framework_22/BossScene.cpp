#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "CollisionManager.h";
#include "BulletManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "UIManager.h"
#include "EventManager.h"
#include "Background.h"
#include "AllEnemies.h"
#include "Player.h"
#include "EnemyProjectile.h"
#include "DelayedCall.h"

void BossScene::Init()
{
	//m_finalBossAllowed = false;
	Background* b = new Background;
	AddObject(b, LAYER::BACKGROUND);


	m_player = new Player;
	AddObject(m_player, LAYER::PLAYER);

	{
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ITEM);
	}
	{
		GET_SINGLE(UIManager)->SetActiveChild(L"FirstScore", true);
		GET_SINGLE(UIManager)->SetActiveChild(L"SecondeScore", true);
		GET_SINGLE(UIManager)->SetActiveChild(L"ThirdScore", true);
	}
	{
		GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart1", true);
		GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart2", true);
		GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart3", true);

	}
	{
		GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
		GET_SINGLE(ResourceManager)->LoadSound(L"InGameBGM", L"Sound\\InGameBGM.mp3", true);
		//GET_SINGLE(ResourceManager)->PlayAudio(L"InGameBGM");
	}
	


	//new DelayedCall(3.f, { {SCREEN_WIDTH * 0.2f , 5.f }, EnemyType::TrashMob2, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 8 });
	//new DelayedCall(3.f, { {SCREEN_WIDTH * 0.5f , 5.f }, EnemyType::TrashMob2, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 8 });
	//new DelayedCall(3.f, { {SCREEN_WIDTH * 0.8f , 5.f }, EnemyType::TrashMob2, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 8 });
	//
	//new DelayedCall(11.f, { {SCREEN_WIDTH * 0.2f , 5.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//new DelayedCall(11.f, { {SCREEN_WIDTH * 0.8f , 5.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//
	//new DelayedCall(17.f, { {SCREEN_WIDTH * 0.8f , -60.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//new DelayedCall(17.f, { {SCREEN_WIDTH * 0.8f , SCREEN_HEIGHT * 0.3f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//
	//new DelayedCall(17.f, { {SCREEN_WIDTH * 0.2f , -60.f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//new DelayedCall(17.f, { {SCREEN_WIDTH * 0.2f , SCREEN_HEIGHT * 0.3f }, EnemyType::TrashMob1, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
	//
	//new DelayedCall(25.f, { {SCREEN_WIDTH * 0.2f , 5.f }, EnemyType::TrashMob3, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 100 });
	new DelayedCall(0.f, { {SCREEN_WIDTH * 0.2f , 5.f }, EnemyType::TrashMob3, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 1 });
}

void BossScene::Update()
{
	Scene::Update();
	if (GET_SINGLE(EventManager)->GetBossEnter())
	{
		GET_SINGLE(EventManager)->SetBossEnter(false);
		new DelayedCall(1.f, { {SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f}, EnemyType::MidBoss, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 100 });
	}
}


BossScene::~BossScene()
{
	
}
