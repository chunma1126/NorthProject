#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "CollisionManager.h";
#include "BulletManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "UIManager.h"
#include "Background.h"
#include "EnemyBullet.h"
#include "AllEnemies.h"
#include "Player.h"

void BossScene::Init()
{
    //bgm
    {
        GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\BGM2.mp3", true);
        GET_SINGLE(ResourceManager)->PlayAudio(L"BGM");
        //GET_SINGLE(ResourceManager)->Volume(SOUND_CHANNEL::BGM, 0.25f);
    }
    //ui
    {
        GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart1", true);
        GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart2", true);
        GET_SINGLE(UIManager)->SetActiveChild(L"PlayerHeart3", true);
    }
    //layer
    {
        GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
        GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
        GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
    }

    {
        TrashMob2* t = new TrashMob2(L"EnemySheetBlue", L"Texture\\EnemySheet_Blue.bmp");
        t->SetScene(this);

        t->SetSize({ 100,100 });
        t->SetPos({ SCREEN_WIDTH / 2 , 0 });
        t->SetTag(TagEnum::Enemy);

        AddObject(t, LAYER::ENEMY);
    }
    
    //background
    {
        Background* b = new Background;
        AddObject(b, LAYER::BACKGROUND);
    }

    //player
    {
        m_player = new Player;
        m_player->SetSize({ 100.f,100.f });
        m_player->SetPos({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });
        AddObject(m_player, LAYER::PLAYER);
    }
}




