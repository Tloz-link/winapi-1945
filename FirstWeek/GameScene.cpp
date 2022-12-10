#include "pch.h"
#include "GameScene.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Square.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Init()
{
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{300, 650});
		GET_SINGLE(ObjectManager)->Add(player);
	}

	for (int32 i = 0; i < 5; ++i)
	{
		Square* monster = GET_SINGLE(ObjectManager)->CreateObject<Square>();
		monster->SetPos(Pos{static_cast<float>((i + 1) * 100), 100});
		GET_SINGLE(ObjectManager)->Add(monster);
	}
}

void GameScene::Update()
{
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* obj : objects)
	{
		obj->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* obj : objects)
	{
		obj->Render(hdc);
	}
}
