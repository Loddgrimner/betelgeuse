#pragma once
#include "component.h"

class smoke:public component
{
public:
	smoke ();
	virtual ~smoke ();
	
	void receivemessage(message msg);
	void update();

private:
	int x;
	int y;
	int time=0;
};
