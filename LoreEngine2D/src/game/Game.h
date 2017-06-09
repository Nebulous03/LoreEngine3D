#pragma once
#include "..\graphics\Window.h"
#include "..\logic\TickHandler.h"
#include "Instance.h"
#include <map>

#define GAME_STOPPED	0
#define GAME_RUNNING	1
#define GAME_PAUSED		2

class TickHandler; // This is bad...

class Game {

private:
	static int _status;
	static Window* _activeWindow;
	static Instance* _activeInstance;

	static TickHandler* _tickHandler;

public:
	Game();

	void start();
	void stop();

	virtual void onStart()	= 0;
	virtual void onStop()	= 0;
	virtual void onTick()	= 0;
	virtual void onUpdate() = 0;

	static void loadInstance(Instance* instance);
	static void unloadActiveInstance();

	static Instance* getActiveInstance();

	static Window* getActiveWindow();
	static void linkWindow(Window* window);

	static int getStatus();

	~Game();

};