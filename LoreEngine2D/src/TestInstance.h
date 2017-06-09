#pragma once
#include "game\Instance.h"
#include "logic\Updatables.h"

class TestInstance : public Instance , public Tickable, public Updateable {

public:
	TestInstance();
	void onLoad();
	void onUnload();
	void onTick();
	void onUpdate();
};