#pragma once
#include "Creature.h"

class Player : public Creature
{
public:
	Player();
	virtual ~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

