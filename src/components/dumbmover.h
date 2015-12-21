#pragma once
#include "component.h"

class dumbmover:public component
{
public:
	dumbmover ();
	virtual ~dumbmover ();
	
	void receivemessage(message msg);
	void update();

private:
	int x = 20;
	int y = 20;
	int dx = 0;
	int dy = 0;
	/* data */
};
