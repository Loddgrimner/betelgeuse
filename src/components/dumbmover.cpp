#include <stdlib.h>
#include "dumbmover.h"

dumbmover::dumbmover()
{
	delta.setx(rand()%10-5);
	delta.sety(rand()%10-5);

	speed = 50;
	movepoints = 0;

}
dumbmover::~dumbmover()
{
}
void dumbmover::update()
{
	if(movepath.getsize() == 0)
	{
		movepath.calculate(position, position + delta);
		movepath.pop_front();
	}

	if(movepath.getsize() != 0)
	{
		movepoints += speed;
		if(movepoints > 100)
		{
			movepoints -= 100;
			ivec2 moveposition = movepath.getcurrent();
			message msg;
			msg.set("changeposition",1);
			msg.set("x",moveposition.getx());
			msg.set("y",moveposition.gety());
			sendmessage(msg);
			movepath.pop_front();
			if(getregistry()->checkposition(moveposition))
			{
				component::killhost();
			}	
		}
		
	}

}
void dumbmover::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		position.setx(msg.get("x"));
		position.sety(msg.get("y"));
	}
	if(msg.get("changedelta"))
	{
		delta.setx(msg.get("deltax"));
		delta.sety(msg.get("deltay"));
	}
}
