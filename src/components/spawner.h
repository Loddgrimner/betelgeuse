#pragma once
#include "component.h"

class spawner:public component
{
public:
	spawner ();
	virtual ~spawner ();
	
	void receivemessage(message msg);
	void update();

private:
	int x;
	int y;
	int spawntimer = 99;
};
