#pragma once
#include "..\game\Game.h"
#include "Updatables.h"
#include <vector>

class Game;	// This is bad...

class TickHandler {

private:
	static Game* _game;
	static double _UPS;
	static std::vector<Tickable*> _tickables;
	static std::vector<Updateable*> _updatables;
	static std::vector<FastUpdateable*> _fastUpdatables;

public:
	TickHandler(Game&, double);
	static void registerTickEvent(Tickable*);
	static void registerUpdateEvent(Updateable*);
	static void registerFastUpdateEvent(FastUpdateable*);

	void run();

	void tickAll();
	void updateAll();
	void fastUpdateAll();

};