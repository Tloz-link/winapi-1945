#pragma once
#include "Bullet.h"

class StraightBullet : public Bullet
{
public:
	StraightBullet();
	virtual ~StraightBullet();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

