#pragma once
#include "game\Scene.h"

class TestScene : public Scene {

public:
	TestScene();
	void onLoad();
	void onUnload();
	void onTick();
	void onUpdate();
	void onRender();
};