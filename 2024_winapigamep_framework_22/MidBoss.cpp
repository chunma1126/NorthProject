#include "pch.h"
#include "MidBoss.h"
#include "BulletManager.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
#include "Texture.h"
MidBoss::MidBoss(const wstring& _key, const wstring& _path)
	: Enemy(_key, _path)
{
	m_stateMachine = new StateMachine();

	m_texture = GET_SINGLE(ResourceManager)->TextureLoad(L"Boss", L"Texture\\Boss.bmp");
}

MidBoss::~MidBoss()
{

}

void MidBoss::Update()
{
	Enemy::Update();
	Vec2 curPos = GetPos();
	m_stateMachine->UpdateState();

	m_timer += fDT;
	if (m_timer >= m_shotTime)
	{
		Shot();
	}
}
void MidBoss::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_texture->GetWidth();
	int height = m_texture->GetHeight();

	::TransparentBlt(_hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width + vSize.x / 2, height + vSize.y / 2,
		m_texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
}
void MidBoss::Shot()
{
	m_timer = 0;
	int idx = cnt % 5;
	float angle = arr[idx];
	cnt++;
	GET_SINGLE(BulletManager)->CircleShot({ GetPos().x ,GetPos().y + 50 }, m_curScene, angle, 400);
}
