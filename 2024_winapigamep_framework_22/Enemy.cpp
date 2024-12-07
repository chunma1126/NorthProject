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
#include "Item.h"
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

	m_deadTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Explosion", L"Texture\\explosion.bmp");
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Explosion", m_deadTexture, { 0,0 }, { 32,32 }, { 32,0 }, 9, 0.1f, false);

	SetTag(TagEnum::Enemy);

	GET_SINGLE(ResourceManager)->LoadSound(L"EnemyDead", L"Sound\\EnemyDead.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"EnemyHit", L"Sound\\EnemyHit.wav", false);
	/*AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Enemy_1", m_texture, { 0,0 }, { 16,16 }, { 16,0 }, 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy_1", true);
	GetComponent<Animator>()->SetSize({ 10,10 });*/
}

Enemy::~Enemy()
{
	m_mt.seed(m_rd());
	std::uniform_int_distribution<int> random(0, 100);
	int rand = random(m_mt);

	/*if (rand < 30)
	{
		Item* item = new Item;
		item->SetPos(GetPos());
		GET_SINGLE(EventManager)->CreateObject(item, LAYER::PLAYER);
	}*/
	Item* item = new Item;
	item->SetPos(GetPos());
	GET_SINGLE(EventManager)->CreateObject(item, LAYER::PLAYER);

	cout << "ÇØÁ¦µÊ" << endl;
}

void Enemy::Update()
{
	if (m_vPos.y < -m_vSize.y || m_vPos.y > SCREEN_HEIGHT + m_vSize.y ||
		m_vPos.x < -m_vSize.x || m_vPos.x > SCREEN_WIDTH + m_vSize.x)
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}

	m_shotTimer += fDT;

	if (m_health->IsDead() && m_explosionComplete)
	{
		GET_SINGLE(UIManager)->AddScore(5);
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
	else if (m_health->IsDead())
	{
		m_explosionTimer += fDT;
		if (m_explosionTime <= m_explosionTimer)
		{
			m_explosionComplete = true;
		}
	}

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

		GET_SINGLE(ResourceManager)->PlayAudio(L"EnemyHit");
		if (m_health->IsDead()) 
		{
			m_isDead = true;
			GetComponent<Animator>()->PlayAnimation(L"Explosion",false);
			GET_SINGLE(ResourceManager)->PlayAudio(L"EnemyDead");
		}
	}
}

void Enemy::StayCollision(Collider* _other)
{
}

void Enemy::ExitCollision(Collider* _other)
{
}

