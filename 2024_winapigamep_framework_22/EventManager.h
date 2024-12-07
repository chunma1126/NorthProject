#pragma once
class Object;
struct tEvent
{
	EVENT_TYPE eveType;
	Object* obj;
	LAYER objType;
public:
	bool operator==(const tEvent& other)
	{
		return eveType == other.eveType && obj == other.obj;
	}
};
class EventManager
{
	DECLARE_SINGLE(EventManager);
public:
	void Update();
	void DeleteObject(Object* _pObj);
	void CreateObject(Object* _pObj,LAYER _layer);

	bool GetBossEnter() { return m_isBossEnter; }
	void SetBossEnter(bool _active) { m_isBossEnter = _active; }

	bool GetPlayerDead() { return m_isPlayerDie; }
	void SetPlayerDead(bool isDead) { m_isPlayerDie = isDead; }
private:
	void Excute(const tEvent& _eve);
private:
	bool m_isBossEnter;
	bool m_isPlayerDie;

	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;

	
};