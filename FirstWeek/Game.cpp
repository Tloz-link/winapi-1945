#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"

Game::Game()
{

}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();
	GET_SINGLE(ResourceManager)->Clear();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);

	::GetClientRect(_hwnd, &_rect);

	_hdcBack = ::CreateCompatibleDC(_hdc);
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(ResourceManager)->Init(hwnd, fs::path(L"C:\\develop\\windowsAPI\\2d\\Resources"));

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::DevScene);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	
	{
		wstring str = format(L"fps ({0}), dt ({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		Utils::DrawText(_hdcBack, Pos{650, 10}, str);
	}

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = format(L"Mouse ({0}, {1})", mousePos.x, mousePos.y);
		Utils::DrawTextW(_hdcBack, Pos{20, 10}, str);
	}

	GET_SINGLE(SceneManager)->Render(_hdcBack);

	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
