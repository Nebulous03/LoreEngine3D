#include "Input.h"

Window* Input::_window;
bool Input::_keys[MAX_KEYS];
bool Input::_buttons[MAX_KEYS];
double Input::_mx, Input::_my;
bool Input::_mouseCaptured;

Input::Input(Window& window)
{
	_window = &window;	// Prob with reseting window
	for (int i = 0; i < MAX_KEYS; i++) _keys[i] = false;
	for (int i = 0; i < MAX_BUTTONS; i++) _buttons[i] = false;
}

void Input::init()
{
	glfwSetKeyCallback(_window->getGLWindow(), key_callback);
	glfwSetMouseButtonCallback(_window->getGLWindow(), button_callback);
	glfwSetCursorPosCallback(_window->getGLWindow(), mouse_callback);
}

bool Input::isKeyPressed(uint keyCode)
{
	if (keyCode < MAX_KEYS)
		return _keys[keyCode];
	else return false;
}

bool Input::isKeyHeld(uint keyCode)
{
	return 0;
}

bool Input::isKeyReleased(uint keyCode)
{
	return 0;
}

bool Input::isButtonPressed(uint buttonCode)
{
	if (buttonCode < MAX_BUTTONS)
		return _buttons[buttonCode];
	else return false;
}

bool Input::isButtonHeld(uint buttonCode)
{
	return 0;
}

bool Input::isButtonReleased(uint buttonCode)
{
	return 0;
}

double Input::getMouseX()
{
	return _mx;
}

double Input::getMoustY()
{
	return _my;
}

vec2f Input::getMousePos()
{
	return Vector2f((float)_mx, (float)_my);
}

void Input::captureMouse()
{
	glfwSetInputMode(_window->getGLWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	_mouseCaptured = true;
}

void Input::releaseMouse()
{
	glfwSetInputMode(_window->getGLWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	_mouseCaptured = false;
}

bool Input::isMouseCaptured()
{
	return _mouseCaptured;
}

void Input::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	_keys[key] = (action != GLFW_RELEASE);
}

void Input::button_callback(GLFWwindow* window, int button, int action, int mods)
{
	_buttons[button] = (action != GLFW_RELEASE);
}

void Input::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	// TODO: get pointer to glfw xpos maybe? (Save copy calls)
	_mx = xpos;
	_my = ypos;
}