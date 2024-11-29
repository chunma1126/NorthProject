#pragma once
#include "Scene.h"
#include "Object.h"

class Projectile;

struct ShotInfo
{
	Vec2 pos;
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
	void BasicShot(ShotInfo& _shotInfo , Vec2 _dir);
	void CircleShot(ShotInfo& _shotInfo);
	void CircleShotGoToTarget(ShotInfo& _shotInfo,Object* _target,float _changeTime);
	void ShapeShot(ShotInfo& _shotInfo, Vec2 _dir ,int _vertex, float _size,float _rotationSpeed);


#pragma region Spinshot
	void SpinShot(ShotInfo& _shotInfo, float& _spinAngle, float _turnSpeed, float _endTime);
	void ApplySpinShot();
#pragma endregion

#pragma region HeartShot
	void HeartShot(ShotInfo& _shotInfo);
	void HeartShotGoToTarget(ShotInfo& _shotInfo, Object* _target, float _changeTime);
	void HeartDataInit(float _rotation);
#pragma endregion

#pragma region RoseShot
	void RoseShot(ShotInfo& _shotInfo, Vec2 _dir,int _petals, float _size);
	void RoseSpinShot(ShotInfo& _shotInfo, Object* _target,int _petals, float _size, float _endTime,float _rotationSpeed);
	void ApplyRoseSpinShot();
#pragma endregion

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
	vector<Projectile*> m_roseVec;
	Vec2 m_roseDir;

	bool m_isRoseShot;
	bool m_roseShotEnd;

	int m_rosePetals;
	int m_roseCount;

	float m_roseEndTime;
	float m_roseEndTimer;
	float m_roseRotationSpeed;
	float m_roseShotTimer;
	float m_roseSize;

};

