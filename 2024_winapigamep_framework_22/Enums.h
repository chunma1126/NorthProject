#pragma once
enum class LAYER
{
	DEFAULT,
	BACKGROUND,
	PLAYER,
	PROJECTILE,
	ENEMY,
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
	Player
};
enum class EnemyType 
{
	Normal,
	TrashMob1,
	MidBoss,
	CircleOut
};

