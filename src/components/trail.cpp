#include "trail.h"

trail::trail()
{
}

trail::~trail()
{
}

void trail::update()
{
	message buildmsg;
	buildmsg.set("lifetimer",1);
	buildmsg.set("lifetime",30);
	buildmsg.set("smoke",1);
	buildmsg.set("changeposition",1);
	buildmsg.set("x",x);
	buildmsg.set("y",y);
	buildentity(buildmsg);
}

void trail::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}
