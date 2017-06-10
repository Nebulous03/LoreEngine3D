#pragma once
#include "game\Scene.h"
#include "logic\Updatables.h"

class TestScene : public Scene, public Tickable, public Updateable {

public:
	TestScene();
	void onLoad();
	void onUnload();
	void onTick();
	void onUpdate();
};