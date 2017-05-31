#pragma once
#include "..\graphics\Window.h"
#include "Instance.h"
#include <map>

#define GAME_STOPPED	0
#define GAME_RUNNING	1
#define GAME_PAUSED		2

class Game {

private:
	Game();
	static int _status;
	static Window* _activeWindow;
	static std::map<const char*, Instance*> _activeInstances;

public:

	static void start();
	static void tick();
	static void stop();

	static void loadInstance(const char* instanceName, Instance& instance);
	static void unloadInstance(const char* instanceName);
	static void clearAllInstances();
	static void updateAllInstances();

	static Instance* getActiveInstances();

	static Window* getActiveWindow();
	static void setActiveWindow(Window* window);

};