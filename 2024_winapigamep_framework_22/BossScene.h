#pragma once
#include "Scene.h"
class DelayedCall;
class Player;
class Background;
class BossScene : public Scene
{
public:
	void Init() override;
private :
	Player* m_player;
	Background* m_backGround;
	DelayedCall* midBoss;


};

