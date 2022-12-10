#include "pch.h"
#include "StraightBullet.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "Creature.h"

StraightBullet::StraightBullet()
{

}

StraightBullet::~StraightBullet()
{

}

void StraightBullet::Init()
{
	_stat.size = 15;
	_stat.speed = 700;
	_stat.attack = 2;

	_collisionRange = 10;
}

void StraightBullet::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_pos.y -= _stat.speed * deltaTime;

	if (_pos.y < -100 || _pos.y > 900)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}

	// Ãæµ¹
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();

	for (Object* obj : objects)
	{
		if (obj->GetObjectType() != ObjectType::Monster)
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

void StraightBullet::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, _stat.size);
}
