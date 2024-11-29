#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthComponent.h"
Enemy::Enemy()
{
	this->SetTag(TagEnum::Enemy);
	this->AddComponent<Collider>();
	this->AddComponent<HealthComponent>();
	m_health = this->GetComponent<HealthComponent>();
	m_health->SetHP(10);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Render(HDC _hdc)
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


void Enemy::EnterCollision(Collider* _other)
{
	//std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	//wstring str = pOtherObj->GetName();
	if (pOtherObj->GetTag() == TagEnum::PlayerProjectile)
	{
		const float damagedTaken = 1;
		m_health->TakeDamage(damagedTaken);
		if(m_health->IsDead())
			GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	//std::cout << "Exit" << std::endl;
}

