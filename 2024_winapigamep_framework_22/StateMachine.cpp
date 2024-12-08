#include "pch.h"
#include "StateMachine.h"
#include "AllStates.h"
#include "State.h"
StateMachine::StateMachine(MidBoss* midBoss)
{
	m_stateHT[MidBossState::p1] = new MBS_p1(midBoss);
	m_stateHT[MidBossState::p2] = new MBS_p2(midBoss);
	m_stateHT[MidBossState::p3] = new MBS_p3(midBoss);
	m_stateHT[MidBossState::p4] = new MBS_p4(midBoss);
	m_stateHT[MidBossState::p5] = new MBS_p5(midBoss);
	m_stateHT[MidBossState::p6] = new MBS_p6(midBoss);
	m_currentState = m_stateHT[MidBossState::p1];
	m_currentState->Enter();
}

StateMachine::~StateMachine()
{
	for (auto& pair : m_stateHT) {
		delete pair.second;
	}
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
