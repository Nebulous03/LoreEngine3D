#pragma once

#define COMPONENT_TYPE_NONE 0

class Component
{
protected:
	unsigned short _typeID = 0;
public:
	Component(unsigned short type) : _typeID(type) {}
	inline unsigned short getType() const { return _typeID; }
};