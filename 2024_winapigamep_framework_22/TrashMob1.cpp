#include "pch.h"
#include "TrashMob1.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Texture.h"
#include "ResourceManager.h"


TrashMob1::TrashMob1(const wstring& _key, const wstring& _path)
{
	m_texture = GET_SINGLE(ResourceManager)->TextureLoad(L"Enemy_1" , L"Texture\\Enemy_1");


	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Enemy_1", m_texture, { 0,0 }, { 15,16 }, { 1,0 }, 5, 1);
	GetComponent<Animator>()->PlayAnimation(L"Enemy_1", true);

	AddComponent<Collider>();
}

TrashMob1::~TrashMob1()
{

}

void TrashMob1::Update()
{	 
	Vec2 down = { 0.f,40*fDT };
	Vec2 curPos = GetPos();
	SetPos(curPos + down);
}	 
	 


