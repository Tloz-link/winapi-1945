#include "pch.h"
#include "Square.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "SqaureBullet.h"

Square::Square() : Creature(ObjectType::Monster)
{

}

Square::~Square()
{

}

void Square::Init()
{
	_stat.hp = 5;
	_stat.maxHp = 5;
	_stat.speed = 100.f;
	_stat.shotDelay = 1.f;

	_collisionRange = 25;
	_currentTick = 0.f;
}

void Square::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_currentTick += deltaTime;

	if (_currentTick >= _stat.shotDelay)
	{
		SqaureBullet* bullet = GET_SINGLE(ObjectManager)->CreateObject<SqaureBullet>();
		bullet->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(bullet);

		_currentTick = 0.f;
	}
}

void Square::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, 50, 50);
}