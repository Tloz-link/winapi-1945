#pragma once
#include "Object.h"

class Creature : public Object
{
public:
	Creature(ObjectType type);
	virtual ~Creature();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	void Damaged(int32 damage);

protected:
	Stat _stat = {};
	float _currentTick = 0.f;
};

