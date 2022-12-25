#pragma once

enum class ObjectType
{
	None,
	Monster,
	Player,
	Projectile,
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }
	Pos GetPos() { return _pos; }
	void SetPos(Pos pos) { _pos = pos; }

	int32 GetCollisionRange() { return _collisionRange; }

protected:
	ObjectType _type = ObjectType::None;
	Pos _pos = {};
	int32 _collisionRange = 0;
};