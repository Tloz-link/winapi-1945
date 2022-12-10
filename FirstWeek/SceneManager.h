#pragma once

class SceneManager
{
	DECRATE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();

public:
	void ChangeScene(SceneType type);

private:
	SceneType _type = SceneType::None;
	class Scene* _scene;
};

