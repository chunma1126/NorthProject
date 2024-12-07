#include "pch.h"
#include "RestartButton.h"
#include "SceneManager.h"
#include "UIManager.h"
#include "EventManager.h"
void RestartButton::ClickEvent()
{
	GET_SINGLE(UIManager)->ResetScore();

	GET_SINGLE(SceneManager)->LoadScene(L"BossScene");

	GET_SINGLE(UIManager)->SetActiveChild(L"GameOver", false);
	GET_SINGLE(UIManager)->SetActiveChild(L"Clear", false);

	GET_SINGLE(UIManager)->SetActiveChild(L"RestartButton", false);
	GET_SINGLE(EventManager)->SetPlayerDead(false);

}
