#pragma once
#include "UI.h"
class Texture;
class Button: public UI
{
public:
	RECT GetRect();
	bool MouseInRect();

	void Update() override;
	void SetPressTexture(Texture* _tex) 
	{
		m_originTexture = m_pTexture;
		m_pressTexture = _tex; 
	}
	void ChangeTex(Texture* _tex);

private :
	RECT m_rect;
	BUTTON_STATE m_state;

	Texture* m_pressTexture;
	Texture* m_originTexture;
};

