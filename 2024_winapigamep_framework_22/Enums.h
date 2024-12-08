#pragma once
enum class LAYER
{
	DEFAULT,
	BACKGROUND,
	PLAYER,
	PROJECTILE,
	ENEMY,
	ITEM,
	// UI
	END
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};

enum class BUTTON_STATE 
{
	DEFAULT,
	HOVER,
	CLICK,
};

enum class TagEnum 
{
	None,
	EnemyProjectile,
	PlayerProjectile,
	Enemy,
	Item,
	Player
};
enum class EnemyType 
{
	Normal,
	TrashMob1,
	TrashMob2,
	TrashMob3,
	MidBoss,
	CircleOut
};

enum class MidBossState
{
	p1 = 0,
	p2,
	p3,
	p4,
	p5,
	p6
};