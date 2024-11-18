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

    GET_SINGLE(BulletManager)->CircleShotGoToTarget(this,13,200,p);

}


