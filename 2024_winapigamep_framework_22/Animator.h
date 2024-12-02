#pragma once
#include "Component.h"
class Texture;
class Animation;
class Object;
class Animator : public Component
{
public:
	Animator();
	~Animator();
public:
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
public:
	// 애니메이션 생성함수
	void CreateAnimation(const wstring& _strName, Texture* _pTex,
		Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep,
		UINT _framecount, float _fDuration, bool _isRotate = false);
	// 애니메이션 찾기함수
	Animation* FindAnimation(const wstring& _strName);

	// 애니메이션 플레이 함수
	void PlayAnimation(const wstring& _strName, bool _IsRepeat, int _repeatcnt = 1);
	void StopAnimation();
public:
	Animation* GetCurrentAnim() { return m_pCurrentAnimation; }
	const bool& GetRepeat() const { return m_IsRepeat; }
	const int& GetRepeatcnt() const { return m_repeatcnt; }
	void SetRepeatcnt() { --m_repeatcnt; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetSize(Vec2 _vSize) { m_vSize = _vSize; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetSize() const { return m_vSize; }
private:
	map<wstring, Animation*> m_mapAnimations;
	Animation* m_pCurrentAnimation;
	bool	m_IsRepeat;
	int		m_repeatcnt;
	Vec2 m_vSize;
	Vec2 m_vPos;
};

