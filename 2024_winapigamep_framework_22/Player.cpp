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
Player::Player()
	: m_pTex(nullptr)
{
	//m_pTex = new Texture;
	//wstring path = GET_SINGLE(ResourceManager)->GetResPath();
	//path += L"Texture\\planem.bmp";
	//m_pTex->Load(path);
	//m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\planem.bmp");
	GET_SINGLE(ResourceManager)->LoadSound(L"PlayerShoot", L"Sound\\guntest.mp3", false);

	//m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\Player_ship.bmp");
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\jiwoo.bmp");
	m_pHitbox = GET_SINGLE(ResourceManager)->TextureLoad(L"Hitbox", L"Texture\\Heart.bmp");
	this->AddComponent<Collider>();
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Player_shipFront", m_pTex, Vec2(0.f, 150.f),
		Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.5f);
	GetComponent<Animator>()->PlayAnimation(L"Player_shipFront", true);
}
Player::~Player()
{
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}
void Player::Update()
{
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
	//RECT_RENDER(_hdc, vPos.x, vPos.y
	//	, vSize.x, vSize.y);
	//::BitBlt(_hdc
	//	, (int)(vPos.x - vSize.x / 2)
	//	, (int)(vPos.y - vSize.y / 2)
	//	, width, height,
	//	m_pTex->GetTexDC()
	//	,0,0,SRCCOPY
	//);
	//::TransparentBlt(_hdc
	//	, (int)(vPos.x - width / 2)
	//	, (int)(vPos.y - height / 2)
	//	, width, height,
	//	m_pTex->GetTexDC()
	//	, 0, 0,width, height, RGB(255,0,255));
	RECT_RENDER(_hdc, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, boundary.x, boundary.y);
	ComponentRender(_hdc);
	if (isSlow)
	{
		int width = m_pHitbox->GetWidth();
		int height = m_pHitbox->GetHeight();
		::TransparentBlt(_hdc
			, (int)(vPos.x - width / 2)
			, (int)(vPos.y - height / 2)
			, width, height,
			m_pHitbox->GetTexDC()
			, 0, 0, width, height, RGB(255, 0, 255));
	}
	//::StretchBlt();
	//::AlphaBlend();
	//::PlgBlt();
}

void Player::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetTag() == TagEnum::EnemyProjectile)
	{
		cout << "d";
		Object* owner = _other->GetOwner();
		Enemy* enemy = owner->GetComponent<Enemy>();
		//if (enemy != nullptr)
		//	enemy.Kill();
	}
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
	pProj->SetSize({30.f,30.f});
	pProj->SetDir({0.f, -1.f});
	pProj->SetName(L"PlayerBullet");
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
}

void Player::CreateUltmite()
{
	cout << "created ultimite\n";
}
