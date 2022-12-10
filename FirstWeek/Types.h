#pragma once

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;

using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;

struct Stat
{
	int32 hp = 0;
	int32 maxHp = 0;
	float speed = 0.f;
	float shotDelay = 0.f;
};

struct BulletStat
{
	int32 size = 0;
	float speed = 0.f;
	int32 attack = 0;
};

struct Pos
{
	float x = 0;
	float y = 0;
};