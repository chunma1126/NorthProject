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
		
		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart" , L"Texture\\UI\\PlayerHeart.bmp"));
		playerHeart->SetPos({50 , 50});
		playerHeart->SetSize({75,75});
		AddChild(L"PlayerHeart1", playerHeart);
	}

	{
		UI* playerHeart = new UI;

		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart", L"Texture\\UI\\PlayerHeart.bmp"));
		playerHeart->SetPos({ 100 , 50 });
		playerHeart->SetSize({ 75,75 });
		AddChild(L"PlayerHeart2", playerHeart);
	}

	{
		UI* playerHeart = new UI;

		playerHeart->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerHeart", L"Texture\\UI\\PlayerHeart.bmp"));
		playerHeart->SetPos({ 150 , 50 });
		playerHeart->SetSize({ 75,75 });
		AddChild(L"PlayerHeart3", playerHeart);
	}

	{
		UI* Title = new UI;

		Title->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Title", L"Texture\\UI\\Title.bmp"));
		Title->SetPos({225, 200 });
		Title->SetSize({ 800,200 });

		AddChild(L"Title", Title);
	}

	{
		PlayButton* playButton = new PlayButton;
		playButton->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"PlayButton", L"Texture\\UI\\PlayButton.bmp"));
		playButton->SetPos({ SCREEN_WIDTH / 2 - 140  , SCREEN_HEIGHT / 2});
		playButton->SetSize({ 600,200 });

		Texture* hover = (GET_SINGLE(ResourceManager)->TextureLoad(L"PlayButtonHover", L"Texture\\UI\\PlayButtonHover.bmp"));
		playButton->SetHoverTexture(hover);

		Texture* press = (GET_SINGLE(ResourceManager)->TextureLoad(L"PlayButtonPress", L"Texture\\UI\\PlayButtonPress.bmp"));
		playButton->SetPressTexture(press);

		AddChild(L"PlayButton", playButton);
	}

	{
		ExitButton* exitButton = new ExitButton;
		exitButton->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"QuitButton", L"Texture\\UI\\QuitButton.bmp"));
		exitButton->SetPos({ SCREEN_WIDTH / 2 - 140 , SCREEN_HEIGHT / 2 + 130 });
		exitButton->SetSize({ 600,200 });

		Texture* hover = (GET_SINGLE(ResourceManager)->TextureLoad(L"QuitButtonHover", L"Texture\\UI\\QuitButtonHover.bmp"));
		exitButton->SetHoverTexture(hover);

		Texture* press = (GET_SINGLE(ResourceManager)->TextureLoad(L"QuitButtonPress", L"Texture\\UI\\QuitButtonPress.bmp"));
		exitButton->SetHoverTexture(hover);
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
