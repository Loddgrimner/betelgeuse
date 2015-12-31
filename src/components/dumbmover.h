#pragma once
#include "component.h"
#include "ivec2.h"
#include "path.h"

class dumbmover:public component
{
public:
	dumbmover ();
	virtual ~dumbmover ();
	
	void receivemessage(message msg);
	void update();

private:
	ivec2 position;
	ivec2 delta;
	path movepath;
	int speed;
	int movepoints;
};
