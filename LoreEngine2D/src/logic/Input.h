#pragma once
#include "../graphics/Window.h"

#define MAX_KEYS	1024
#define MAX_BUTTONS 16

class Input
{
private:
	Window* _window;
	static bool _keys[MAX_KEYS];
	static bool _buttons[MAX_KEYS];
	static double _mx, _my;

public:
	Input(Window& window);
	void initInput();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};