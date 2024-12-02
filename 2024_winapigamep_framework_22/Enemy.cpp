#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthComponent.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Animator.h"
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

	/*AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Enemy_1", m_texture, { 0,0 }, { 16,16 }, { 16,0 }, 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy_1", true);
	GetComponent<Animator>()->SetSize({ 10,10 });*/
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Render(HDC _hdc)
{	
	/*Vec2 vPos = GetPos();
	int width = m_texture->GetWidth();
	int height = m_texture->GetHeight();*/
	
	ComponentRender(_hdc);

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

