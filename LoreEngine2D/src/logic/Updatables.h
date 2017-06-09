#pragma once

class Tickable {

protected:
	Tickable() {};

public:
	virtual void onTick() = 0;

};

class Updateable {

protected:
	Updateable() {};

public:
	virtual void onUpdate() = 0;

};

class FastUpdateable {

protected:
	FastUpdateable() {};

public:
	virtual void onFastUpdate() = 0;

};