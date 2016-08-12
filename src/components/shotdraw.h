#pragma once
#include "component.h"

class shotdraw:public component
{
public:
	shotdraw ();
	virtual ~shotdraw ();
	
	void receivemessage(message msg);
	void update();

private:
	ivec2 position;
	ivec2 delta;
};
