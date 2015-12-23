#pragma once
#include "component.h"

class trail:public component
{
public:
	trail ();
	virtual ~trail ();
	
	void receivemessage(message msg);
	void update();

private:
	int x;
	int y;
};
