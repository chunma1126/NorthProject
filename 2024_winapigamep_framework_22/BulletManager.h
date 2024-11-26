#pragma once
#include "Scene.h"
#include "Object.h"

class FollowProjectile;

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
	void Init();
	void Update();
	void CircleShot(ShotInfo& _shotInfo);
	void CircleShotGoToTarget(ShotInfo& _shotInfo,Object* target,float changeTime);

	void SpinShot(ShotInfo& _shotInfo, float& spinAngle, float turnSpeed,float endTime);
	void ApplySpinShot();

	void ShapeShot(ShotInfo& _shotInfo, Vec2 dir ,int vertex, float size,float rotationSpeed);

	void HeartShot(ShotInfo& _shotInfo);
	void HeartShotGoToTarget(ShotInfo& _shotInfo , Object* target,float changeTime);
	void HeartDataInit(float _rotation);

	void RoseShot(ShotInfo& _shotInfo, int petals, float size);
	void RoseSpinShot(ShotInfo& _shotInfo, Object* _target,int petals, float size, float time);
	void ApplyRoseSpinShot();

private:
	 Object* m_target;

	#pragma region spinshot
	ShotInfo m_spinShotInfo;

	bool m_isSpinShot;

	float m_spinTurnSpeed;
	float m_spinAngle;
	float m_spinShotTimer;
	float m_spinEndTime;
	float m_spinEndTimer;
	#pragma endregion



	 //HeartShot
	 float m_heartRotation;
private:
	 float m_speeds[34];
	 float m_direction[34];

	 //rose spinShot
private : 
	ShotInfo m_roseShotInfo;
	bool m_isRoseShot;
	float m_roseTimer;
	float m_roseShotTimer;
	float m_roseEndTime;
	int m_rosePetals;
	float m_roseSize;
	vector<FollowProjectile*> m_roseVec;


};

