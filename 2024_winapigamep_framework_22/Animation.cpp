#include "pch.h"
#include "Animation.h"
#include "Animator.h"
#include "Object.h"
#include "Texture.h"
#include "TimeManager.h"
Animation::Animation()
	: m_pAnimator(nullptr)
	, m_CurFrame(0)
	, m_pTex(nullptr)
	, m_fAccTime(0.f)
{
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (m_pAnimator->GetRepeatcnt() <= 0)
	{
		m_CurFrame = m_vecAnimFrame.size() - 1;
		return;
	}
	m_fAccTime += fDT;
	// 누적한 시간이 내가 이 프레임에 진행한 시간을 넘어섰냐?
	if (m_fAccTime >= m_vecAnimFrame[m_CurFrame].fDuration)
	{
		// 일단 모은 시간에서 현재 진행한 시간을 빼고
		m_fAccTime -= m_vecAnimFrame[m_CurFrame].fDuration;
		++m_CurFrame; // 다음프레임으로 옮기기
		if (m_CurFrame >= m_vecAnimFrame.size()) // 한바퀴 돌게하고싶어
		{
			if (!m_pAnimator->GetRepeat())
				m_pAnimator->SetRepeatcnt();
			m_CurFrame = 0;
			m_fAccTime = 0.f;
		}

	}
}

void Animation::Render(HDC _hdc, Vec2 _pos, Vec2 _size)
{
	Object* pObj = m_pAnimator->GetOwner();
	Vec2 vPos = pObj->GetPos();

	// 오프셋 적용
	vPos = vPos + m_vecAnimFrame[m_CurFrame].vOffset;

	// 스케일링된 크기 계산
	Vec2 scaledSize = Vec2(
		m_vecAnimFrame[m_CurFrame].vSlice.x * _size.x,
		m_vecAnimFrame[m_CurFrame].vSlice.y * _size.y
	);

	TransparentBlt(_hdc,
		// 렌더링 위치 계산 (입력된 _pos 기준)
		(int)(_pos.x + (vPos.x - scaledSize.x / 2.f)),
		(int)(_pos.y + (vPos.y - scaledSize.y / 2.f)),
		// 스케일링된 크기 적용
		(int)(scaledSize.x),
		(int)(scaledSize.y),
		// 텍스처 좌표
		m_pTex->GetTexDC(),
		(int)(m_vecAnimFrame[m_CurFrame].vLT.x),
		(int)(m_vecAnimFrame[m_CurFrame].vLT.y),
		(int)(m_vecAnimFrame[m_CurFrame].vSlice.x),
		(int)(m_vecAnimFrame[m_CurFrame].vSlice.y),
		RGB(255, 0, 255));
}


void Animation::Create(Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, int _framecount, float _fDuration, bool _isRotate)
{
	m_pTex = _pTex;
	m_IsRotate = _isRotate;
	for (int i = 0; i < _framecount; ++i)
	{
		m_vecAnimFrame.push_back(tAnimFrame({ _vLT + _vStep * i,
			_vSliceSize, _fDuration,{0.f,0.f} }));
	}
}
