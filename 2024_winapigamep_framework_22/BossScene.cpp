#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "BulletManager.h"
#include "Player.h"
#include "InputManager.h"
void BossScene::Init()
{
    m_player = new Player;
    m_player->SetSize({100.f,100.f});
    m_player->SetPos({SCREEN_WIDTH/2 , SCREEN_HEIGHT/2});
    AddObject(m_player,LAYER::PLAYER);
    
    ShotInfo shotInfo = { this ,20,300.f };
    ShotInfo shotInfo_1 = { this ,0.015f,300.f };

    /*GET_SINGLE(BulletManager)->HeartDataInit(270.f);
    GET_SINGLE(BulletManager)->HeartShot(shotInfo);

    GET_SINGLE(BulletManager)->HeartShot(shotInfo);

    GET_SINGLE(BulletManager)->HeartDataInit(90.f);
    GET_SINGLE(BulletManager)->HeartShotGoToTarget(shotInfo, m_player, 2.f);

    float angle = 0;
    GET_SINGLE(BulletManager)->SpinShot(shotInfo_1, angle, 1200.f, 12);
    
    GET_SINGLE(BulletManager)->CircleShot(shotInfo);

    GET_SINGLE(BulletManager)->CircleShotGoToTarget(shotInfo, m_player, 1.2f);*/
    /*Vec2 dir = {0, 1};
    GET_SINGLE(BulletManager)->ShapeShot(shotInfo, dir, 3, 40,1.2f);*/

    //GET_SINGLE(BulletManager)->RoseShot(shotInfo , 30 , 200.f);
    GET_SINGLE(BulletManager)->RoseSpinShot(shotInfo_1,m_player,7, 200.f,5);

}




