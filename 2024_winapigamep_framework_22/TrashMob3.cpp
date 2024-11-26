#include "pch.h"
#include "TrashMob3.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"

TrashMob3::TrashMob3()
	: m_hp(5)
{
	this->AddComponent<Collider>();
	
}

TrashMob3::~TrashMob3()
{
}

void TrashMob3::Update()
{	 
	//Vec2 dir = ifPlayerPos - GetPos();
	
}	 
	 
void TrashMob3::Render(HDC _hdc)
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

void TrashMob3::EnterCollision(Collider* _other)
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

void TrashMob3::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void TrashMob3::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
