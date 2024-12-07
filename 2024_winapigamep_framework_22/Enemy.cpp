#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthComponent.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Animator.h"
#include "TimeManager.h"
#include "UIManager.h"
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


	SetTag(TagEnum::Enemy);

	/*AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Enemy_1", m_texture, { 0,0 }, { 16,16 }, { 16,0 }, 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy_1", true);
	GetComponent<Animator>()->SetSize({ 10,10 });*/
}

Enemy::~Enemy()
{
	Object::~Object();

	if (m_texture != nullptr)
	{
		delete m_texture;
		m_texture = nullptr;
	}

	if (m_curScene != nullptr)
	{
		delete m_curScene;
		m_curScene = nullptr;
	}

	if (m_health != nullptr)
	{
		delete m_health;
		m_health = nullptr;
	}

}

void Enemy::Update()
{
	if (m_vPos.y < -m_vSize.y || m_vPos.y > SCREEN_HEIGHT + m_vSize.y ||
		m_vPos.x < -m_vSize.x || m_vPos.x > SCREEN_WIDTH + m_vSize.x)
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}

	m_shotTimer += fDT;

}

void Enemy::Render(HDC _hdc)
{	
	/*Vec2 vPos = GetPos();
	int width = m_texture->GetWidth();
	int height = m_texture->GetHeight();*/
	
	ComponentRender(_hdc);

}

void Enemy::SetHP(float hp)
{
	m_health->SetHP(hp);
}

void Enemy::EnterCollision(Collider* _other)
{
	if (GetComponent<HealthComponent>()->IsDead())return;

	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetTag() == TagEnum::PlayerProjectile)
	{
		const float damagedTaken = 1;
		m_health->TakeDamage(damagedTaken);
		if (m_health->IsDead()) 
		{
			GET_SINGLE(UIManager)->AddScore(5);
			cout << "ÀÀ¾î¾ÆÀÕ";
			GET_SINGLE(EventManager)->DeleteObject(this);
		}
	}
}

void Enemy::StayCollision(Collider* _other)
{
}

void Enemy::ExitCollision(Collider* _other)
{
}

