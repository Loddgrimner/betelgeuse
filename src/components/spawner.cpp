#include "spawner.h"

spawner::spawner()
{
}

spawner::~spawner()
{
}

void spawner::update()
{
	if(spawntimer == 0)
	{
		for(int i = 0; i< 10; i++)
		{
			message msg;
			msg.set("dumbmover",1);
			msg.set("lifetimer",1);
			msg.set("pointdraw",1);
			msg.set("trail",1);
			msg.set("changeposition",1);
			msg.set("x",x);
			msg.set("y",y);
			buildentity(msg);
		}
	}
	spawntimer--;
}

void spawner::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}
