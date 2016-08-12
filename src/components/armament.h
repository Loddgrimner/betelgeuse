#pragma once
#include "component.h"

class armament:public component
{
public:
	armament ();
	virtual ~armament ();
	
	void receivemessage(message msg);
	void update();

private:
	int mteam;
	ivec2 mposition;
	int cooldown = 99;
};
