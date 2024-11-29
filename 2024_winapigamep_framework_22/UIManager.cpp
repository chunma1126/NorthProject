#include "pch.h"
#include "UIManager.h"
#include "UI.h"

void UIManager::Init()
{

}

void UIManager::Update()
{
}

void UIManager::Render(HDC _hdc)
{
	
}

void UIManager::AddChild(wstring _key,UI* _newUI)
{
	uiLists[_key] = _newUI;
}
