#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "DevScene.h"
#include "EditScene.h"

void SceneManager::Init()
{
	
}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}

void SceneManager::ChangeScene(SceneType type)
{
	if (_type == type)
		return;

	Scene* newScene = nullptr;
	switch (type)
	{
	case SceneType::DevScene:
		newScene = new DevScene();
		break;
	case SceneType::EditScene:
		newScene = new EditScene();
		break;
	}

	SAFE_DELETE(_scene);
	_scene = newScene;
	_type = type;

	newScene->Init();
}
