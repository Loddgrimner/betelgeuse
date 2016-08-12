#include <stdlib.h>
#include "randommover.h"

randommover::randommover()
{
	delta.setx(rand()%10-5);
	delta.sety(rand()%10-5);

	speed = rand() % 5 + 1;
	movepoints = 0;

}
randommover::~randommover()
{
}
void randommover::update()
{
	movepoints += speed;
	if(movepoints > 100)
	{
		movepoints -= 100;

		message msg;
		msg.set("changeposition",1);
		msg.set("x",position.getx()+rand()%3-1);
		msg.set("y",position.gety()+rand()%3-1);
		sendmessage(msg);
		movepath.pop_front();
	}
}
void randommover::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		position.setx(msg.get("x"));
		position.sety(msg.get("y"));
	}
}
