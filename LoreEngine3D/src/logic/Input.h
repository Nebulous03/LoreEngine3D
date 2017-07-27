#pragma once
#include "../graphics/Window.h"
#include "../math/Math.h"

#define MAX_KEYS	1024
#define MAX_BUTTONS 16

class Input
{
private:
	static Window* _window;
	static bool _keys[MAX_KEYS];
	static bool _buttons[MAX_KEYS];
	static double _mx, _my;
	static bool _mouseCaptured;

public:
	Input(Window& window);
	void init();

	static bool isKeyPressed(uint keyCode);
	static bool isKeyHeld(uint keyCode);
	static bool isKeyReleased(uint keyCode);

	static bool isButtonPressed(uint buttonCode);
	static bool isButtonHeld(uint buttonCode);
	static bool isButtonReleased(uint buttonCode);

	static double getMouseX();
	static double getMoustY();

	static vec2f getMousePos();

	static void captureMouse();
	static void releaseMouse();

	static bool isMouseCaptured();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void button_callback(GLFWwindow* window, int button, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};