#include "pch.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "UI.h"
#include "Button.h"
#include "PlayButton.h"
#include "ExitButton.h"

void UIManager::Init()
{
	for (auto& item : uiLists)
	{
		item.second->Init();
	}

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

	{
		UI* Title = new UI;

		Title->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Title", L"Texture\\Title.bmp"));
		Title->SetPos({400 , 200 });
		Title->SetSize({ 800,200 });

		AddChild(L"Title", Title);
	}

	{
		PlayButton* playButton = new PlayButton;
		playButton->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayButton", L"Texture\\PlayButton.bmp"));
		playButton->SetPos({ 400 , 600 });
		playButton->SetSize({ 400,200 });

		Texture* press = (GET_SINGLE(ResourceManager)->TextureLoad(L"PlayButtonPress", L"Texture\\PlayButtonPress.bmp"));
		playButton->SetPressTexture(press);

		AddChild(L"PlayButton", playButton);
	}

	{
		ExitButton* exitButton = new ExitButton;
		exitButton->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"QuitButton", L"Texture\\QuitButton.bmp"));
		exitButton->SetPos({ 400 , 800 });
		exitButton->SetSize({ 400,200 });

		Texture* press = (GET_SINGLE(ResourceManager)->TextureLoad(L"QuitButtonPress", L"Texture\\QuitButtonPress.bmp"));
		exitButton->SetPressTexture(press);

		AddChild(L"ExitButton", exitButton);
	}
	
}

void UIManager::Update()
{
	//if (GET_KEYDOWN(KEY_TYPE::P))
	//{
	//	SetActiveChild(L"PlayerHeart3", false);
	//}
	//if (GET_KEYDOWN(KEY_TYPE::O))
	//{
	//	SetActiveChild(L"PlayerHeart3", true);
	//}

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
	if (uiLists.find(_key) == uiLists.end())
	{
		return;
	}

	if (uiLists[_key] == nullptr)
	{
		return;
	}

	uiLists[_key]->SetActive(_active);
}

UI* UIManager::GetChild(wstring _key)
{
	return uiLists[_key];
}
