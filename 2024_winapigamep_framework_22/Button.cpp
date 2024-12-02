#include "pch.h"
#include "Button.h"
#include "InputManager.h"

RECT Button::GetRect()
{
	RECT rt = RECT_MAKE(m_vPos.x, m_vPos.y, m_vSize.x, m_vSize.y);

	return rt;
}

bool Button::MouseInRect()
{
	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
	RECT rt = GetRect();

	return PtInRect(&rt, mousePos);
}

void Button::Update()
{
	UI::Update();

	KEY_STATE state = GET_SINGLE(InputManager)->GetKey(KEY_TYPE::LBUTTON);

	if (MouseInRect())
	{
		if (state == KEY_STATE::DOWN)
		{
			ChangeTex(m_pressTexture);
		}
		else if (state == KEY_STATE::UP)
		{
			ChangeTex(m_originTexture);
			ClickEvent();
		}
	}
	else
	{
		ChangeTex(m_originTexture);
	}

}

void Button::ChangeTex(Texture* _tex)
{
	m_pTexture = _tex;
}