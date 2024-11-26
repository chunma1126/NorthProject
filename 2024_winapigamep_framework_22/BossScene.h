#pragma once
#include "Scene.h"
class Player;
class BossScene : public Scene
{
	void Init() override;

private :
	Player* m_player;
};

