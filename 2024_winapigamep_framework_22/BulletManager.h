#pragma once
#include "Scene.h"
#include "Object.h"

class BulletManager
{
	DECLARE_SINGLE(BulletManager);
public:
	void CircleShot(Scene* _scene,float _interval, float bulletSpeed);
	void CircleShotGoToTarget(Scene* _scene, float _interval, float bulletSpeed ,Object* target);

};

