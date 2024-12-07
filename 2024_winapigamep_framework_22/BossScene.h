#pragma once
#include "Scene.h"
class DelayedCall;
class Player;
class Background;
class BossScene : public Scene
{
public:
	~BossScene();
	void Init() override;
	void Update() override;
public:
	static void OnFinalBossEnable() { BossScene::m_finalBossAllowed = true; }
	static bool m_finalBossAllowed;
private:
	Player* m_player;
	Background* m_backGround;
	DelayedCall* midBoss;


};

