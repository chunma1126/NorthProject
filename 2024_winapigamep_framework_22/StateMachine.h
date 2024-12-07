#pragma once

class State;
//just for midboss for now
class StateMachine
{
public:
	StateMachine();
	~StateMachine();
public:
	void ChangeState(MidBossState newState);
	void AddState(MidBossState stateEnum, State state);
	void UpdateState();
	const State& GetCurrentState() { return *m_currentState; }
private:
	State* m_currentState = nullptr;
	std::map<MidBossState, State*> m_stateHT;
};

