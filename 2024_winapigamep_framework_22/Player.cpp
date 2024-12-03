#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Enemy.h"
#include "HealthComponent.h"
Player::Player()
	: m_pTex(nullptr)
{
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerShoot", L"Sound\\guntest.mp3", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerDeath", L"Sound\\PlayerDead.wav", false);

	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\Player.bmp");
	m_pTexOnHurt = GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerOnHurt", L"Texture\\PlayerDeath.bmp");
	m_pHitbox = GET_SINGLE(ResourceManager)->TextureLoad(L"Hitbox", L"Texture\\Heart.bmp");

	SetSize({ 60,60 });
	this->SetTag(TagEnum::Player);
	this->AddComponent<HealthComponent>();
	m_health = this->GetComponent<HealthComponent>();
	m_health->SetHP(4);

	this->AddComponent<Collider>();
	this->GetComponent<Collider>()->SetOffSetPos({ 15.5f, 15.f });
	this->GetComponent<Collider>()->SetSize({ 10,10 });
	m_pFire = GET_SINGLE(ResourceManager)->TextureLoad(L"Fire", L"Texture\\Fire.bmp");
	AddComponent<Animator>();
	GetComponent<Animator>()->SetPos({ 15.5f, 55.f });
	GetComponent<Animator>()->SetSize({ 2.4f,2.4f });
	GetComponent<Animator>()->CreateAnimation(L"Fire", m_pFire, { 0,0 }, { 16,16 }, { 16,0 }, 2, 0.1f, false);
	GetComponent<Animator>()->PlayAnimation(L"Fire", true);

}
Player::~Player()
{
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}
void Player::Update()
{
	m_immortalTime += GET_SINGLE(TimeManager)->GetDT();

	if (GET_KEY(KEY_TYPE::RIGHT))
		TryShoot();
	if (GET_KEYDOWN(KEY_TYPE::LEFT))
		CreateUltmite();
	isSlow = GET_KEY(KEY_TYPE::UP);

	Vec2 dir = Vec2();
	if (GET_KEY(KEY_TYPE::W))
		dir.y -= 1;
	if (GET_KEY(KEY_TYPE::S))
		dir.y += 1;
	if (GET_KEY(KEY_TYPE::A))
		dir.x -= 1;
	if (GET_KEY(KEY_TYPE::D))
		dir.x += 1;

	float speed = isSlow ? defaultSpeed : runningSpeed;
	dir.Normalize();
	dir = dir * (fDT * speed);

	Vec2 vPos = GetPos();
	SetPos(vPos + dir);
	//Clamp();
}

void Player::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	bool isImmortal = IsImmortal();
	cout << vSize.x << "\n";
	if (isImmortal)
	{
		::TransparentBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width + vSize.x / 2, height + vSize.y / 2,
			m_pTexOnHurt->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	else {
		::TransparentBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width + vSize.x / 2, height + vSize.y / 2,
			m_pTex->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	if (isSlow)
	{
		int width = m_pHitbox->GetWidth();
		int height = m_pHitbox->GetHeight();
		::TransparentBlt(_hdc
			, (int)(vPos.x - width / 2) + pivotPoint.x
			, (int)(vPos.y - height / 2) + pivotPoint.y
			, width, height,
			m_pHitbox->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}

	ComponentRender(_hdc);
	//::StretchBlt();
	//::AlphaBlend();
	//::PlgBlt();
}

void Player::EnterCollision(Collider* _other)
{
	OnHit(_other);
}

void Player::StayCollision(Collider* _other)
{
	OnHit(_other);
}

void Player::Clamp()
{
	int x = GetPos().x;
	int y = GetPos().y;
	cout << x << " " << y << SCREEN_WIDTH << "_" << SCREEN_HEIGHT << "\n";
}

bool Player::TryShoot()
{
	float delay = 60 / rpm;
	float currentTime = GET_SINGLE(TimeManager)->GetTime();
	bool canShot = lastShotTime + delay < currentTime;
	if (canShot)
	{
		GET_SINGLE(ResourceManager)->PlayAudio(L"PlayerShoot");
		CreateProjectile();
		lastShotTime = currentTime;
	}
	return canShot;
}

bool Player::TryUltimite()
{
	bool result = false;
	if (result)
	{
		CreateUltmite();
	}
	return result;
}

void Player::CreateProjectile()
{
	Projectile* pProj = new Projectile;
	pProj->SetSpeed(1000);
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 30.f,30.f });
	pProj->SetDir({ 0.f, -1.f });
	pProj->SetTag(TagEnum::PlayerProjectile);
	//pProj->SetName(L"PlayerBullet");
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
}

void Player::CreateUltmite()
{
	cout << "created ultimite\n";
}

void Player::Dead()
{
	cout << "PLAYER dead, game over\n";
}

void Player::OnHit(Collider* _other)
{
	if (IsImmortal()) return;
	Object* pOtherObj = _other->GetOwner();
	TagEnum pOtherObjTag = pOtherObj->GetTag();
	switch (pOtherObjTag)
	{
	case TagEnum::EnemyProjectile:
	case TagEnum::Enemy:
		m_health->TakeDamage(1);
		OnTakeDamage();
		break;
	}

}

void Player::OnTakeDamage()
{
	SetPos(spawnPosition);
	m_immortalTime = 0;
	GET_SINGLE(ResourceManager)->PlayAudio(L"PlayerDeath");
	if (m_health->GetHP() <= 0)
	{
		Dead();
		return;
	}

}
