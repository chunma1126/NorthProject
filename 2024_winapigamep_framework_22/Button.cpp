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
			ChangeTex(m_pressTexture,BUTTON_STATE::CLICK);
		}
		else if (state == KEY_STATE::UP)
		{
			ChangeTex(m_originTexture, BUTTON_STATE::DEFAULT);
			ClickEvent();
		}
		else {
			ChangeTex(m_hoverTexture, BUTTON_STATE::HOVER);
		}
	}
	else
	{
		ChangeTex(m_originTexture, BUTTON_STATE::DEFAULT);
	}

}

void Button::ChangeTex(Texture* _tex,BUTTON_STATE _state)
{
	m_pTexture = _tex;
	m_state = _state;
}