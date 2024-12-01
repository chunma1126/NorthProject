#include "pch.h"
#include "UIManager.h"
#include "UI.h"
#include "SceneManager.h"


void UIManager::Init()
{

}

void UIManager::Update()
{
	
}

void UIManager::Render(HDC _hdc)
{
	RECT_RENDER(_hdc,SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 , 10 , 10);
}

void UIManager::AddChild(wstring _key,UI* _newUI)
{
	uiLists[_key] = _newUI;
}
