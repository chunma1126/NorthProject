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
#include "UIManager.h"
#include "UI.h"
#include "Camera.h"
#include "CameraComponent.h"
#include "EventManager.h"
Player::Player()
	: m_pTex(nullptr)
{

	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerShoot", L"Sound\\PlayerShot.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerHit", L"Sound\\PlayerHit.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerDead", L"Sound\\PlayerDead.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerPowerUp", L"Sound\\PowerUp.wav", false);
	
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\Player.bmp");
	m_pTexOnHurt = GET_SINGLE(ResourceManager)->TextureLoad(L"PlayerOnHurt", L"Texture\\PlayerDeath.bmp");
	m_pHitbox = GET_SINGLE(ResourceManager)->TextureLoad(L"Hitbox", L"Texture\\Heart.bmp");

	SetSize({ 60,60 });
	SetPos(spawnPosition);
	this->SetTag(TagEnum::Player);
	this->AddComponent<HealthComponent>();
	m_health = this->GetComponent<HealthComponent>();
	m_health->SetHP(4);

	this->AddComponent<Collider>();
	this->GetComponent<Collider>()->SetOffSetPos({ 15.5f, 17.5f });
	this->GetComponent<Collider>()->SetSize({ 7,7 });
	m_pFire = GET_SINGLE(ResourceManager)->TextureLoad(L"Fire", L"Texture\\Fire.bmp");
	AddComponent<Animator>();
	GetComponent<Animator>()->SetPos({ 15.5f, 54.f });
	GetComponent<Animator>()->SetSize({ 2.4f,2.4f });
	GetComponent<Animator>()->CreateAnimation(L"Fire", m_pFire, { 0,0 }, { 16,16 }, { 16,0 }, 2, 0.1f, false);
	GetComponent<Animator>()->PlayAnimation(L"Fire", true);

	AddComponent<CameraComponent>();
	GetComponent<CameraComponent>()->SetOwner(this);

	m_explosion = GET_SINGLE(ResourceManager)->TextureLoad(L"Explosion", L"Texture\\explosion.bmp");
	GetComponent<Animator>()->CreateAnimation(L"Explosion", m_explosion, { 0,0 }, { 32,32 }, { 32,0 }, 9, 0.1f, false);
}

Player::~Player()
{
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}
void Player::Update()
{
	if (m_isDead)return;

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

	Vec2 newPos = dir + m_vPos;

	if (newPos.x >= 0 && newPos.x <= SCREEN_WIDTH - 25 &&
		newPos.y >= 0 && newPos.y  <= SCREEN_HEIGHT - 100)
	{
		SetPos(newPos);
	}

	if (GET_KEYDOWN(KEY_TYPE::P))
	{
		OnLevelUp();
	}
}

void Player::Render(HDC _hdc)
{

	if (m_isDead)return;

	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	bool isImmortal = IsImmortal();

	Vec2 screenpos = GET_SINGLE(Camera)->GetCameraPos();

	if (isImmortal)
	{
		::TransparentBlt(_hdc
			, (int)(screenpos.x - width / 2)
			, (int)(screenpos.y - height / 2)
			, width + vSize.x / 2, height + vSize.y / 2,
			m_pTexOnHurt->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	else
	{
		::TransparentBlt(_hdc
			, (int)(screenpos.x - width / 2)
			, (int)(screenpos.y - height / 2)
			, width + vSize.x / 2, height + vSize.y / 2,
			m_pTex->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	if (isSlow)
	{
		int width = m_pHitbox->GetWidth();
		int height = m_pHitbox->GetHeight();
		::TransparentBlt(_hdc
			, (int)(screenpos.x - width / 2) + pivotPoint.x
			, (int)(screenpos.y - height / 2) + pivotPoint.y
			, width + vSize.x / 20, height + vSize.y / 20,
			m_pHitbox->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	ComponentRender(_hdc);

}

void Player::EnterCollision(Collider* _other)
{
	OnHit(_other);
}

void Player::StayCollision(Collider* _other)
{
	OnHit(_other);
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
	Vec2 vPos = GetPos();
	vPos.x += 16.0f;
	vPos.y += -0.2f;

	switch (m_level)
	{
	case 1:
	{
		// 레벨 1: 하나만 발사
		Projectile* pProj = new Projectile;
		pProj->SetSpeed(1000);
		pProj->SetPos(vPos);
		pProj->SetSize({ 30.f, 30.f });
		pProj->SetDir({ 0.f, -1.f });
		pProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
	}
	break;
	case 2:
	{
		Vec2 leftDir = { -0.1f, -1.f };  
		Vec2 rightDir = { 0.1f, -1.f };  

		Projectile* pLeftProj = new Projectile;
		pLeftProj->SetSpeed(1000);
		pLeftProj->SetPos(vPos);
		pLeftProj->SetSize({ 30.f, 30.f });
		pLeftProj->SetDir(leftDir);
		pLeftProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pLeftProj, LAYER::PROJECTILE);

		Projectile* pRightProj = new Projectile;
		pRightProj->SetSpeed(1000);
		pRightProj->SetPos(vPos);
		pRightProj->SetSize({ 30.f, 30.f });
		pRightProj->SetDir(rightDir);
		pRightProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pRightProj, LAYER::PROJECTILE);
	}
	break;
	case 3:
	{
		Projectile* pCenterProj = new Projectile;
		pCenterProj->SetSpeed(1000);
		pCenterProj->SetPos(vPos);
		pCenterProj->SetSize({ 30.f, 30.f });
		pCenterProj->SetDir({ 0.f, -1.f });
		pCenterProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pCenterProj, LAYER::PROJECTILE);

		Vec2 leftDir = { -0.1f, -1.f };
		Projectile* pLeftProj = new Projectile;
		pLeftProj->SetSpeed(1000);
		pLeftProj->SetPos(vPos);
		pLeftProj->SetSize({ 30.f, 30.f });
		pLeftProj->SetDir(leftDir);
		pLeftProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pLeftProj, LAYER::PROJECTILE);

		Vec2 rightDir = { 0.1f, -1.f };
		Projectile* pRightProj = new Projectile;
		pRightProj->SetSpeed(1000);
		pRightProj->SetPos(vPos);
		pRightProj->SetSize({ 30.f, 30.f });
		pRightProj->SetDir(rightDir);
		pRightProj->SetTag(TagEnum::PlayerProjectile);
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pRightProj, LAYER::PROJECTILE);
	}
	break;
	}
}


void Player::CreateUltmite()
{
	cout << "created ultimite\n";
}

void Player::Dead()
{
	m_isDead = true;

	GET_SINGLE(UIManager)->SetActiveChild(L"GameOver", true);
	GET_SINGLE(UIManager)->SetActiveChild(L"RestartButton", true);
	GET_SINGLE(ResourceManager)->PlayAudio(L"PlayerDead");

	GetComponent<Animator>()->SetSize({5,5});
	GetComponent<Animator>()->PlayAnimation(L"Explosion", false);
}

void Player::OnHit(Collider* _other)
{
	if (IsImmortal()) return;

	Object* pOtherObj = _other->GetOwner();
	TagEnum pOtherObjTag = pOtherObj->GetTag();

	switch (pOtherObjTag)
	{
	case TagEnum::Item :
	{
		OnLevelUp();
	}
	break;
	case TagEnum::EnemyProjectile:
	case TagEnum::Enemy:

		m_health->TakeDamage(1);
		OnTakeDamage();
		break;
	}

}

void Player::OnTakeDamage()
{
	GetComponent<CameraComponent>()->Shake(5, 0.7f);

	SetPos(spawnPosition);
	m_immortalTime = 0;
	GET_SINGLE(ResourceManager)->PlayAudio(L"PlayerHit");

	std::wstring healthPath = L"PlayerHeart" + std::to_wstring(static_cast<int>(std::floor(m_health->GetHP())));
	GET_SINGLE(UIManager)->SetActiveChild(healthPath, false);

	if (m_health->GetHP() <= 0)
	{
		Dead();
		return;
	}
}

void Player::OnLevelUp()
{
	GET_SINGLE(ResourceManager)->PlayAudio(L"PlayerPowerUp");
	++m_level;
	if (m_level >= 3)m_level = 3;
}
