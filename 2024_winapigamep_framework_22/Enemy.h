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
	~Enemy();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void SetScene(Scene* _scene) { m_curScene = _scene; }
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
protected:
	Texture* m_texture = nullptr;
	HealthComponent* m_health = nullptr;
	Scene* m_curScene = nullptr;
};

