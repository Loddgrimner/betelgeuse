#include <stdlib.h>
#include "dumbmover.h"

dumbmover::dumbmover()
{
	dx = rand()%3-1;
	dy = rand()%3-1;
}
dumbmover::~dumbmover()
{
}
void dumbmover::update()
{
	message msg;
	msg.set("changeposition",1);
	msg.set("x",x+dx);
	msg.set("y",y+dy);
	sendmessage(msg);
}
void dumbmover::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}
