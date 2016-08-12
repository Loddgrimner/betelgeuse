#pragma once
#include "component.h"

class lifetimer:public component
{
public:
	lifetimer ();
	virtual ~lifetimer ();
	
	void receivemessage(message msg);
	void update();

private:
	int time = 0;
	int killtime = 1000;
};
