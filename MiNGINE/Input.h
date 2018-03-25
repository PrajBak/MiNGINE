#pragma once
#include"Window.h"
#include"GLFW\glfw3.h"
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Input {
	Window* mWindow;
	bool mKeys[MAX_KEYS];
	bool mButtons[MAX_BUTTONS];

public:
	Input() = default;
	Input(Window* window);
	Input(Input& input);
	bool isKeyPressed(int key);
	bool isMouseButtonPressed(int button);
};