#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	Space = VK_SPACE,
	Shift = VK_SHIFT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	Z = 'Z',
};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,

	End,
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)
};

class InputManager
{
	DECRATE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);
	void Update();

	bool GetButton(KeyType type) { return GetState(type) == KeyState::Press; }
	bool GetButtonDown(KeyType type) { return GetState(type) == KeyState::Down; }
	bool GetButtonUp(KeyType type) { return GetState(type) == KeyState::Up; }
	POINT GetMousePos() { return _mousePos; }

private:
	KeyState GetState(KeyType type) { return _states[static_cast<uint8>(type)]; }

private:
	vector<KeyState> _states;
	HWND _hwnd = 0;
	POINT _mousePos;
};

