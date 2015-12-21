#pragma once
#include "component.h"

class pointdraw:public component
{
public:
	pointdraw ();
	virtual ~pointdraw ();
	
	void receivemessage(message msg);
	void update();

private:
	int x;
	int y;
};
