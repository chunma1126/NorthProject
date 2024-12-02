#include "pch.h"
#include "TrashMob1.h"
#include "Collider.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Texture.h"
#include "ResourceManager.h"

TrashMob1::TrashMob1(const wstring& _key, const wstring& _path)
	: Enemy(_key, _path)
{
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"Enemy_1", m_texture, { 0,58 }, { 48,48 }, { 48,0 }, 4, 0.2f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy_1", true);
	GetComponent<Animator>()->SetSize({ 4,4 });


	GetComponent<Collider>()->SetSize({ 125,125 });
}

TrashMob1::~TrashMob1()
{

}


	 


