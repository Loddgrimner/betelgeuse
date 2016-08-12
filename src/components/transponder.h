#pragma once
#include "component.h"
#include "ivec2.h"

class transponder:public component
{
public:
	transponder ();
	virtual ~transponder ();

	void receivemessage(message msg);
	void update();

private:
	bool mregistered = false;
	int mid = 0;
	int mteam = 0;
	ivec2 mposition;
};
