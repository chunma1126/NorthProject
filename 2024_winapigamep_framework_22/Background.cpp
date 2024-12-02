#include "pch.h"
#include "Background.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "TimeManager.h"
Background::Background()
{
	m_pTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Background", L"Texture\\Background.bmp");
}

Background::~Background()
{
}

void Background::Update()
{
    Vec2 curPos = GetPos();

    SetPos({ curPos.x , curPos.y + m_scrollingSpeed * fDT});

    if (curPos.y >= 1080)
        SetPos({0,0});

}

void Background::Render(HDC _hdc)
{
    Vec2 pos = GetPos();

    int width = SCREEN_WIDTH;  
    int height = SCREEN_HEIGHT;

    ::BitBlt(_hdc
        , pos.x 
        , pos.y - SCREEN_HEIGHT
        , width, height,
        m_pTexture->GetTexDC()
        , 0, 0, SRCCOPY);

    ::BitBlt(_hdc
        , pos.x
        , pos.y
        , width, height,              
        m_pTexture->GetTexDC()
        , 0, 0,SRCCOPY);
}

