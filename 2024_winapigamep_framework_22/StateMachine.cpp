#include "pch.h"
#include "StateMachine.h"
#include "AllStates.h"
#include "State.h"
StateMachine::StateMachine()
{
	m_stateHT[MidBossState::p1] = new MBS_p1();
	m_stateHT[MidBossState::p2] = new MBS_p1();
	m_currentState = m_stateHT[MidBossState::p1];
	m_currentState->Enter();
}

StateMachine::~StateMachine()
{
}

void StateMachine::ChangeState(MidBossState newState)
{
	m_currentState->Exit();
	m_currentState = m_stateHT[newState];
	m_currentState->Enter();
}

void StateMachine::AddState(MidBossState stateEnum, State state)
{
	//just do it on constructor
}

void StateMachine::UpdateState()
{
	m_currentState->Update();
}
