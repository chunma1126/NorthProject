#include "pch.h"
#include "TrashMob2.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"

TrashMob2::TrashMob2()
	: m_hp(5)
{
	this->AddComponent<Collider>();
	/*if (m_right) {
		for (int i = 0; i < 150; ++i) {
			Vec2 down = { -40 * fDT,40 * fDT };
			Vec2 curPos = GetPos();
			SetPos(curPos + down);
		}
	}
	else {
		for (int i = 0; i < 150; ++i) {
			Vec2 down = { 40 * fDT,40 * fDT };
			Vec2 curPos = GetPos();
			SetPos(curPos + down);
		}
	}*/
}

TrashMob2::~TrashMob2()
{
}

void TrashMob2::Update()
{	 
	if (m_right) {
			Vec2 down = { -40 * fDT,40 * fDT };
			Vec2 curPos = GetPos();
			SetPos(curPos + down);
	}
	else {
			Vec2 down = { 40 * fDT,40 * fDT };
			Vec2 curPos = GetPos();
			SetPos(curPos + down);
	}
	
}	 
	 
void TrashMob2::Render(HDC _hdc)
{
	//HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	//HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);
	ComponentRender(_hdc);
	//SelectObject(_hdc, oldbrush); 
	//DeleteObject(brush);
}

void TrashMob2::EnterCollision(Collider* _other)
{
	std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	wstring str = pOtherObj->GetName();
	if (pOtherObj->GetName() == L"PlayerBullet")
	{
		m_hp -= 1;
		if (m_hp <= 0)
			GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void TrashMob2::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void TrashMob2::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
