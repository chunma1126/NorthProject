#include "pch.h"
#include "UIManager.h"
#include "UI.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

void UIManager::Init()
{
	{
		UI* playerHeart = new UI;
		
		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart" , L"Texture\\PlayerHeart.bmp"));
		playerHeart->SetPos({50 , 50});
		playerHeart->SetSize({50,50});
		AddChild(L"PlayerHeart1", playerHeart);
	}

	{
		UI* playerHeart = new UI;

		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart", L"Texture\\PlayerHeart.bmp"));
		playerHeart->SetPos({ 100 , 50 });
		playerHeart->SetSize({ 50,50 });
		AddChild(L"PlayerHeart2", playerHeart);
	}

	{
		UI* playerHeart = new UI;

		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart", L"Texture\\PlayerHeart.bmp"));
		playerHeart->SetPos({ 150 , 50 });
		playerHeart->SetSize({ 50,50 });
		AddChild(L"PlayerHeart3", playerHeart);
	}
	

}

void UIManager::Update()
{
	if (GET_KEYDOWN(KEY_TYPE::P))
	{
		SetActiveChild(L"PlayerHeart3", false);
	}
	if (GET_KEYDOWN(KEY_TYPE::O))
	{
		SetActiveChild(L"PlayerHeart3", true);
	}

	for (auto& item : uiLists)
	{
		item.second->Update();
	}
}

void UIManager::Render(HDC _hdc)
{
	for (auto& item : uiLists)
	{
		item.second->Render(_hdc);
	}
}

void UIManager::AddChild(wstring _key,UI* _newUI)
{
	uiLists[_key] = _newUI;
}

void UIManager::SetActiveChild(wstring _key, bool _active)
{
	uiLists[_key]->SetActive(_active);
}
