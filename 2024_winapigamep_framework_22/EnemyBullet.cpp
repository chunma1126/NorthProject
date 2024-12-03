#include "pch.h"
#include "EnemyBullet.h"
#include "ResourceManager.h"
#include "Animator.h"

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

void EnemyBullet::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
