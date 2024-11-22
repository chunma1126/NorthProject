#pragma once
#include "Scene.h"
#include "Object.h"

struct ShotInfo
{
	Scene* scene;
	float interval;
	float bulletSpeed;
};


class BulletManager
{
	DECLARE_SINGLE(BulletManager);
public:
	void Update();
	void CircleShot(ShotInfo _shotInfo);
	void CircleShotGoToTarget(ShotInfo _shotInfo,Object* target);

	void SpinShot(ShotInfo _shotInfo, float& spinAngle, float turnSpeed,float endTime);
	void ApplySpinShot();

	void ShapeShot(ShotInfo _shotInfo, int _m, int _a, float _phi);


	void HeartShot(ShotInfo _shotInfo);
	void HeartDataInit();

private:
	//spinshot
	 ShotInfo m_spinShotInfo;

	 bool m_isSpinShot;

	 float m_spinTurnSpeed;
	 float m_spinAngle;
	 float m_spinShotTimer;
	 float m_endTime;
	 float m_endTimer;

	 Object* m_target;

	 //HeartShot
private:
	 float _speeds[34];
	 float _direction[34];


};

