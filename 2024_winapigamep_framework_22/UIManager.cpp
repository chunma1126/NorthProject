#include "pch.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "UI.h"
#include "Button.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include "RestartButton.h"
#include "EventManager.h"
#include "GDISelector.h"

void UIManager::Init()
{
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
		UI* gameOver = new UI;

		gameOver->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"GameOver", L"Texture\\UI\\GameOver.bmp"));
		gameOver->SetSize({ 1350,150 });
		gameOver->SetPos({ SCREEN_WIDTH / 2 - 340 , SCREEN_HEIGHT / 2 - 150});
		AddChild(L"GameOver", gameOver);
		
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

	{
		RestartButton* restartButton = new RestartButton;
		restartButton->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"RestartButton", L"Texture\\UI\\RestartButton.bmp"));
		restartButton->SetPos({ SCREEN_WIDTH / 2 - 140  , SCREEN_HEIGHT / 2 });
		restartButton->SetSize({ 600,200 });

		Texture* hover = (GET_SINGLE(ResourceManager)->TextureLoad(L"RestartButtonHover", L"Texture\\UI\\RestartButtonHover.bmp"));
		restartButton->SetHoverTexture(hover);

		Texture* press = (GET_SINGLE(ResourceManager)->TextureLoad(L"RestartButtonPress", L"Texture\\UI\\RestartButtonPress.bmp"));
		restartButton->SetPressTexture(press);

		AddChild(L"RestartButton", restartButton);
	}

	for (auto& item : uiLists)
	{
		item.second->Init();
	}
}

void UIManager::Update()
{
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

void UIManager::ChangeScore()
{



}



UI* UIManager::GetChild(wstring _key)
{
	return uiLists[_key];
}
