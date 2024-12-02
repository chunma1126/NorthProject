#include "pch.h"
#include "TrashMob1.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"

TrashMob1::TrashMob1()
	: m_hp(5)
{
	this->AddComponent<Collider>();
}

TrashMob1::~TrashMob1()
{
}

void TrashMob1::Update()
{	 
	//Vec2 dir = ifPlayerPos - GetPos();
	Vec2 down = { 0.f,40*fDT };
	Vec2 curPos = GetPos();
	SetPos(curPos + down);

}	 
	 
void TrashMob1::Render(HDC _hdc)
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

void TrashMob1::EnterCollision(Collider* _other)
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

void TrashMob1::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void TrashMob1::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
