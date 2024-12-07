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
#include "EnemyProjectile.h"

void BossScene::Init()
{
	m_backGround = new Background;
	AddObject(m_backGround, LAYER::BACKGROUND);

	m_player = new Player;
	AddObject(m_player, LAYER::PLAYER);

	{
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
		GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
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
		GET_SINGLE(ResourceManager)->PlayAudio(L"InGameBGM");
	}


	 midBoss = new DelayedCall(0.f, { {SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f}, EnemyType::MidBoss, L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp", 10 });
}




BossScene::~BossScene()
{
	delete midBoss;
}





