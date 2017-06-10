#pragma once
#include "..\graphics\Window.h"
#include "..\logic\TickHandler.h"
#include "Scene.h"
#include <map>

#define GAME_STOPPED	0
#define GAME_RUNNING	1
#define GAME_PAUSED		2

class TickHandler; // This is bad...

class Game {

private:
	int _status;
	Graphics* _graphics;
	Window* _activeWindow;
	TickHandler* _tickHandler;
	Scene* _activeScene;

public:
	Game();

	void start();
	void stop();

	virtual void onStart()	= 0;
	virtual void onStop()	= 0;
	virtual void onTick()	= 0;
	virtual void onUpdate() = 0;

	void loadScene(Scene* scene);
	void unloadActiveInstance();

	Scene* getActiveScene();
 
	Graphics* getGraphics();

	Window* getActiveWindow();
	void linkWindow(Window* window);

	int getStatus();

	~Game();

};