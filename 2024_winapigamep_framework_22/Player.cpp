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
Player::Player()
	: m_pTex(nullptr)
{
	//m_pTex = new Texture;
	//wstring path = GET_SINGLE(ResourceManager)->GetResPath();
	//path += L"Texture\\planem.bmp";
	//m_pTex->Load(path);
	//m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\planem.bmp");
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Jiwoo", L"Texture\\jiwoo.bmp");
	m_pHitbox = GET_SINGLE(ResourceManager)->TextureLoad(L"Hitbox", L"Texture\\Hitbox.bmp");
	this->AddComponent<Collider>();
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"JiwooFront", m_pTex, Vec2(0.f, 150.f),
		Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"JiwooFront", true);

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

	float speed = isSlow ? runningSpeed : defaultSpeed;
	dir.Normalize();
	dir = dir * (fDT * speed);

	Vec2 vPos = GetPos();
	SetPos(vPos + dir);
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

bool Player::TryShoot()
{
	float delay = 0.1f;
	float currentTime = GET_SINGLE(TimeManager)->GetTime();
	bool canShot = lastShotTime + delay < currentTime;
	//system("cls");
	cout << "\n " << currentTime;
	if (canShot)
	{
		cout << "shoot";
		CreateProjectile();
		lastShotTime = currentTime;
	}
	return canShot;
}

void Player::CreateProjectile()
{
	Projectile* pProj = new Projectile;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({30.f,30.f});
	// �� -> ����: PI / 180
	//pProj->SetAngle(PI / 4 * 7.f); // 1
	//static float angle = 0.f;
	//pProj->SetAngle(angle * PI / 180); // 2
	//angle += 10.f;
	pProj->SetDir({0.f, -1.f});
	pProj->SetName(L"PlayerBullet");
	//Vec2 a = { 10.f, 10.f };
	//Vec2 b = { 0.f, 0.f };
	//Vec2 c = a / b;

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
}

void Player::CreateUltmite()
{
}
