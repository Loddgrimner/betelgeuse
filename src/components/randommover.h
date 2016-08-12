#pragma once
#include "component.h"
#include "ivec2.h"
#include "path.h"

class randommover:public component
{
public:
	randommover ();
	virtual ~randommover ();
	
	void receivemessage(message msg);
	void update();

private:
	ivec2 position;
	ivec2 delta;
	path movepath;
	int speed;
	int movepoints;
};
