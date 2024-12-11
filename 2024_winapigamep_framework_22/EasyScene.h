#pragma once
#include "Scene.h"
class DelayedCall;
class Player;
class Background;
class EasyScene : public Scene
{
public:
	EasyScene(wstring _sceneName);
	~EasyScene();
	void Init() override;
	void Update() override;
public:
private:
	Player* m_player;
	Background* m_backGround;
};

