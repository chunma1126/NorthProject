#include "pch.h"
#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::LateUpdate()
{
}

void HealthComponent::Render(HDC _hdc)
{
}

void HealthComponent::TakeDamage(float amount)
{
	m_hp -= amount;
	DamageCalculation();
}

void HealthComponent::DamageCalculation()
{
	if (m_hp <= 0)
	{
		m_hp = 0;
		m_isDead = true;
	}
}
