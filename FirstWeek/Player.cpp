#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "StraightBullet.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"

Player::Player() : Creature(ObjectType::Player)
{

}

Player::~Player()
{

}

void Player::Init()
{
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 700;
	_stat.shotDelay = 0.1f;

	_collisionRange = 1;
	_currentTick = 1.f;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Shift))
		_stat.speed = 300;
	else
		_stat.speed = 700;

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Left))
	{
		_pos.x -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Right))
	{
		_pos.x += _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Up))
	{
		_pos.y -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Down))
	{
		_pos.y += _stat.speed * deltaTime;
	}

	_pos.x = clamp(_pos.x, 10.f, 590.f);
	_pos.y = clamp(_pos.y, 10.f, 790.f);

	// 자동 연사
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Z))
	{
		_currentTick += deltaTime;

		if (_currentTick >= _stat.shotDelay)
		{
			StraightBullet* bullet = GET_SINGLE(ObjectManager)->CreateObject<StraightBullet>();
			bullet->SetPos(Pos(_pos.x, _pos.y - 10));
			GET_SINGLE(ObjectManager)->Add(bullet);

			_currentTick = 0.f;
		}
	}
}

void Player::Render(HDC hdc)
{
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
	{
		mesh->Render(hdc, _pos);
	}
}
