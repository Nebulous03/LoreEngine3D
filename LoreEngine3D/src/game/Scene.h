#pragma once

class Scene {

public:
	virtual void onLoad()	= 0;
	virtual void onUnload() = 0;
	virtual void onTick()	= 0;
	virtual void onUpdate() = 0;
	virtual void onRender() = 0;

};
