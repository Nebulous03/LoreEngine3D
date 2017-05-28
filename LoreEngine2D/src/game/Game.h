#pragma once
#include "..\graphics\Window.h"

#define GAME_STOPPED	0
#define GAME_RUNNING	1
#define GAME_PAUSED		2

class Game {

private:
	Game();
	static Window* _activeWindow;
	static int _status;

public:
	static void start();
	static void tick();
	static void stop();
	static Window* getActiveWindow();
	static void setActiveWindow(Window* window);

};