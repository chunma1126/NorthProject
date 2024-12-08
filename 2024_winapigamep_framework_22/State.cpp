#include "pch.h"
#include "State.h"
#include "MidBoss.h"
State::State(MidBoss* midboss)
{
	m_midBoss = midboss;
}

State::~State()
{
}

void State::Enter()
{
}

void State::Update()
{
}

void State::Exit()
{
}
