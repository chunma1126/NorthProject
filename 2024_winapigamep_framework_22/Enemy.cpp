#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthComponent.h"
#include "ResourceManager.h"
Enemy::Enemy()
{
	this->SetTag(TagEnum::Enemy);
	this->AddComponent<Collider>();
	this->AddComponent<HealthComponent>();
	m_health = this->GetComponent<HealthComponent>();
	m_health->SetHP(4);
}
Enemy::Enemy(const wstring& _key, const wstring& _path)
{
	this->SetTag(TagEnum::Enemy);
	this->AddComponent<Collider>();
	this->AddComponent<HealthComponent>();
	m_health = this->GetComponent<HealthComponent>();
	m_health->SetHP(4);
	m_texture = GET_SINGLE(ResourceManager)->TextureLoad(_key, _path);
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
	//Vec2 vPos = GetPos();
	//Vec2 vSize = GetSize();
	//RECT_RENDER(_hdc, vPos.x, vPos.y
	//	, vSize.x, vSize.y);
	ComponentRender(_hdc);
	//SelectObject(_hdc, oldbrush); 
	//DeleteObject(brush);
}


void Enemy::EnterCollision(Collider* _other)
{
	Object* pOtherObj = _other->GetOwner();
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
}

void Enemy::ExitCollision(Collider* _other)
{
}

