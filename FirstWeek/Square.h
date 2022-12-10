#pragma once
#include "Creature.h"

class Square : public Creature
{
public:
	Square();
	virtual ~Square();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};