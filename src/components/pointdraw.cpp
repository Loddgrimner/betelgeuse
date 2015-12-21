#include <stdlib.h>
#include <ncurses.h>
#include "pointdraw.h"

pointdraw::pointdraw()
{
}
pointdraw::~pointdraw()
{
}
void pointdraw::update()
{
	mvprintw(x,y,"@");
}
void pointdraw::receivemessage(message msg)
{
	if(msg.get("changeposition"))
	{
		x = msg.get("x");
		y = msg.get("y");
	}
}

