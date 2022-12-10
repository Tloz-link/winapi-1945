#pragma once
#include "Bullet.h"

class SqaureBullet : public Bullet
{
public:
	SqaureBullet();
	virtual ~SqaureBullet();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};