#include "pch.h"
#include "EnemyBullet.h"
#include "ResourceManager.h"
#include "Animator.h"
#include "EventManager.h"
EnemyBullet::EnemyBullet()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"EnemyBullet",L"Texture\\FireBullet.bmp");

	AddComponent<Animator>();
	GetComponent<Animator>()->SetSize({1,1});
	GetComponent<Animator>()->CreateAnimation(L"EnemyBullet", m_pTex, { 0,0 }, { 24.f,29.f }, {24,0} , 8 ,0.08f, false);
	GetComponent<Animator>()->PlayAnimation(L"EnemyBullet" , true);

}



EnemyBullet::~EnemyBullet()
{
}

//void EnemyBullet::Update()
//{
//	Projectile::Update();
//
//
//	if (m_vPos.y < -m_vSize.y || m_vPos.y > SCREEN_HEIGHT + m_vSize.y ||
//		m_vPos.x < -m_vSize.x || m_vPos.x > SCREEN_WIDTH + m_vSize.x)
//	{
//		GET_SINGLE(EventManager)->DeleteObject(this);
//	}
//}

void EnemyBullet::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
