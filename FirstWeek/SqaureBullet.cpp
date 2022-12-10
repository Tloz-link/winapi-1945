#include "pch.h"
#include "SqaureBullet.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "Creature.h"

SqaureBullet::SqaureBullet()
{

}

SqaureBullet::~SqaureBullet()
{

}

void SqaureBullet::Init()
{
	_stat.size = 10;
	_stat.speed = 400;
	_stat.attack = 1;

	_collisionRange = 10;
}

void SqaureBullet::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_pos.y += _stat.speed * deltaTime;

	if (_pos.y < -100 || _pos.y > 900)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}

	// Ãæµ¹
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();

	for (Object* obj : objects)
	{
		if (obj->GetObjectType() != ObjectType::Player)
			continue;

		Creature* creature = static_cast<Creature*>(obj);

		Pos p1 = GetPos();
		Pos p2 = creature->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < _collisionRange + creature->GetCollisionRange())
		{
			creature->Damaged(_stat.attack);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}
	}
}

void SqaureBullet::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, _stat.size);
}
