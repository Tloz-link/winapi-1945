#include "pch.h"
#include "Creature.h"
#include "ObjectManager.h"

Creature::Creature(ObjectType type) : Object(type)
{

}

Creature::~Creature()
{

}

void Creature::Damaged(int32 damage)
{
	_stat.hp -= damage;
	if (_stat.hp <= 0)
		GET_SINGLE(ObjectManager)->Remove(this);
}
