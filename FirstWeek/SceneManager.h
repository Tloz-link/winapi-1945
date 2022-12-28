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
	class Scene* _scene = {};

public:
	Vec2 GetCameraPos() { return _cameraPos; }
	void SetCameraPos(Vec2 pos) { _cameraPos = pos; }

private:
	Vec2 _cameraPos = {0, 0};
};

