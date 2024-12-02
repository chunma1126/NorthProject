#include "pch.h"
#include "PlayButton.h"
#include "SceneManager.h"
#include "UIManager.h"

void PlayButton::ClickEvent()
{
	if (!m_active)return;


	cout << "시작입니다 " << endl;

	GET_SINGLE(UIManager)->SetActiveChild(L"Title", false);
	GET_SINGLE(UIManager)->SetActiveChild(L"PlayButton", false);
	GET_SINGLE(UIManager)->SetActiveChild(L"ExitButton", false);

	GET_SINGLE(SceneManager)->LoadScene(L"BossScene");
}
