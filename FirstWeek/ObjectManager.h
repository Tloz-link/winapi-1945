#pragma once

class Object;

class ObjectManager
{
	DECRATE_SINGLE(ObjectManager);

public:
	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* Object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject()
	{
		static_assert(is_convertible_v<T*, Object*>);

		T* obj = new T();
		obj->Init();
		return obj;
	}

private:
	vector<Object*> _objects;
};

