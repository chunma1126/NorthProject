#include "pch.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "UIManager.h"
#include "TimeManager.h"
#include "Core.h"
#include "Background.h"
#include "UI.h"
void TitleScene::Init()
{
	Background* b = new Background;
	AddObject(b, LAYER::BACKGROUND);


	GET_SINGLE(UIManager)->SetActiveChild(L"Title",true);
    GET_SINGLE(UIManager)->SetActiveChild(L"PlayButton", true);
}

void TitleScene::Update()
{
    Scene::Update();

    if (GET_KEYDOWN(KEY_TYPE::ENTER))
        GET_SINGLE(SceneManager)->LoadScene(L"BossScene");
    
}


