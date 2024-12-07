#pragma once
#include "Object.h"
class Texture;
class HealthComponent;
class Scene;
class Enemy :
    public Object
{
public:
	Enemy();
	Enemy(const wstring& _key, const wstring& _path);
	virtual ~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void SetScene(Scene* _scene) { m_curScene = _scene; }
	void SetHP(float hp);
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);

protected:
	Texture* m_texture = nullptr;
	Texture* m_deadTexture = nullptr;
	HealthComponent* m_health = nullptr;
	Scene* m_curScene = nullptr;
	bool m_isDead;
protected:
	float stayTime = 3.f;
	float stayTimer = 0;

	float m_shotTime = 1;
	float m_shotTimer = 0;
	
	bool dirRight = true;
	float m_explosionTime = 1.f;
	float m_explosionTimer;
	bool m_explosionComplete = false;

	std::random_device m_rd;
	std::mt19937 m_mt;
};

