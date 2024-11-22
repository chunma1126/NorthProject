#include "pch.h"
#include "BossScene.h"
#include "ResourceManager.h"
#include "BulletManager.h"
#include "Player.h"


void BossScene::Init()
{
    Player* p = new Player;
    p->SetSize({100.f,100.f});
    p->SetPos({SCREEN_WIDTH/2 , SCREEN_HEIGHT/2});
    AddObject(p,LAYER::PLAYER);

    ShotInfo shotInfo = {this ,20,400.f};
    ShotInfo shotInfo_1 = { this ,0.005,400.f };
    float angle = 0;

    //GET_SINGLE(BulletManager)->SpinShot(shotInfo_1, angle , 10000.f, 12);
    //GET_SINGLE(BulletManager)->SpinShotGoToTarget(shotInfo_1, angle, 10000.f, 3.5f, p);

    //GET_SINGLE(BulletManager)->CircleShotGoToTarget(shotInfo,p);
    //GET_SINGLE(BulletManager)->CircleShot(shotInfo);

    GET_SINGLE(BulletManager)->HeartDataInit();
    GET_SINGLE(BulletManager)->HeartShot(shotInfo);
}


