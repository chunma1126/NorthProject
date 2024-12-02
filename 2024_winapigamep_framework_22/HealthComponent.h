#pragma once
#include "Component.h"
class HealthComponent : public Component
{
public:
	HealthComponent();
	~HealthComponent();
public:
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void TakeDamage(float amount);
	const float& GetHP() { return m_hp; }
	void SetHP(float hp) { m_hp = hp; }
	const bool& IsDead() { return m_isDead; }
private:
	void DamageCalculation();
	bool m_isDead = false;
	float m_hp;
};