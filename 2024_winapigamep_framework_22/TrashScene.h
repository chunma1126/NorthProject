#pragma once
#include "Scene.h"
class TrashScene : public Scene
{
    void Init() override;
    
public:
    Vec2 enemyPos1 = { 85.f,66.f };
    Vec2 enemyPos2 = { 1195.f,66.f };
    Vec2 enemyPos3 = { SCREEN_WIDTH / 2.f,150.f };
    
};

